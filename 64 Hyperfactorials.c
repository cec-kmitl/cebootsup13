#include <stdio.h>
#include <stdlib.h>
#include <string.h> // สำหรับ strlen, memset

// เลือก BASE ที่เหมาะสม:
// - BASE = 10: ง่ายต่อการเข้าใจแต่ละหลัก แต่ช้ามากสำหรับตัวเลขใหญ่
// - BASE = 1,000,000,000 (10^9): เร็วขึ้นมาก เพราะแต่ละ chunk เก็บได้ 9 หลัก
//   และผลคูณของสอง chunk จะพอดีกับ unsigned long long (10^9 * 10^9 = 10^18 < 2^64)

#define BASE 1000000000 // 10^9
#define MAX_CHUNKS 300000   // จำนวน chunk ที่คาดว่าจะเพียงพอสำหรับ H(10) (H(10) มี 45 หลัก / 9 หลักต่อ chunk = 5 chunks)
                        // แต่ควรเผื่อไว้สำหรับการคูณที่อาจทำให้จำนวน chunk เพิ่มขึ้น

typedef struct {
    unsigned int chunks[MAX_CHUNKS]; // เก็บตัวเลขเป็นฐาน BASE
    int num_chunks;                   // จำนวน chunks ที่ใช้งานจริง
} BigInt;

// prototypes
void BigInt_init(BigInt *num);
void BigInt_set_int(BigInt *num, unsigned long long val);
void BigInt_copy(BigInt *dest, const BigInt *src);
void BigInt_print(const BigInt *num);
void BigInt_add(BigInt *result, const BigInt *a, const BigInt *b);
void BigInt_multiply_by_int(BigInt *result, const BigInt *a, unsigned int val); // คูณ BigInt ด้วย int
void BigInt_multiply(BigInt *result, const BigInt *a, const BigInt *b); // การคูณ BigInt สองตัว
void BigInt_power(BigInt *result, const BigInt *base, int exponent); // ยกกำลัง

int main() {
    int n;
    scanf("%d", &n);

    BigInt hyperfactorial;
    BigInt_init(&hyperfactorial);
    BigInt_set_int(&hyperfactorial, 1); // Hyperfactorial เริ่มต้นด้วย 1

    for (int i = 1; i <= n; i++) {
        BigInt base_val;
        BigInt_init(&base_val);
        BigInt_set_int(&base_val, i); // base_val = i

        BigInt i_power_i;
        BigInt_init(&i_power_i);
        BigInt_power(&i_power_i, &base_val, i); // i_power_i = i^i

        BigInt temp_hyperfactorial;
        BigInt_init(&temp_hyperfactorial);
        BigInt_copy(&temp_hyperfactorial, &hyperfactorial);

        BigInt_multiply(&hyperfactorial, &temp_hyperfactorial, &i_power_i); // hyperfactorial *= (i^i)

        // printf("%d ", i);
        // BigInt_print(&hyperfactorial); // แสดงผลแต่ละขั้น
        // printf("\n");
    }

    BigInt_print(&hyperfactorial);
    printf("\n");

    // นับจำนวนหลัก
    // สำหรับ BASE = 10^9, chunk สุดท้ายจะต้องแปลงเป็น string แล้วนับหลัก
    // ส่วน chunk อื่นๆ (ถ้ามี) จะมี 9 หลักเสมอ
    int count = 0;
    if (hyperfactorial.num_chunks == 0) { // กรณี 0
        count = 1;
    } else {
        // นับหลักของ chunk สุดท้าย
        unsigned int last_chunk = hyperfactorial.chunks[hyperfactorial.num_chunks - 1];
        if (last_chunk == 0) { // กรณี 0 ตัวเดียว
             count = 1;
        } else {
            while (last_chunk > 0) {
                last_chunk /= 10;
                count++;
            }
        }

        // เพิ่มหลักของ chunk ก่อนหน้า (แต่ละ chunk มี 9 หลัก)
        count += (hyperfactorial.num_chunks - 1) * 9;
    }
    printf("[%d]\n", count);

    return 0;
}

// *** IMPLEMENTATION OF BIGINT FUNCTIONS ***

void BigInt_init(BigInt *num) {
    memset(num->chunks, 0, sizeof(num->chunks)); // เคลียร์ทุก chunks เป็น 0
    num->num_chunks = 1; // เริ่มต้นมี 1 chunk ที่เป็น 0
}

void BigInt_set_int(BigInt *num, unsigned long long val) {
    BigInt_init(num);
    int i = 0;
    if (val == 0) {
        num->chunks[0] = 0;
        num->num_chunks = 1;
        return;
    }
    while (val > 0) {
        num->chunks[i] = val % BASE;
        val /= BASE;
        i++;
    }
    num->num_chunks = i;
}

void BigInt_copy(BigInt *dest, const BigInt *src) {
    memcpy(dest->chunks, src->chunks, src->num_chunks * sizeof(unsigned int));
    dest->num_chunks = src->num_chunks;
}

void BigInt_print(const BigInt *num) {
    if (num->num_chunks == 0 || (num->num_chunks == 1 && num->chunks[0] == 0)) {
        printf("0");
        return;
    }

    // พิมพ์ chunk ที่สำคัญที่สุดก่อน (ไม่มีการเติม 0 นำหน้า)
    printf("%u", num->chunks[num->num_chunks - 1]);

    // พิมพ์ chunk ที่เหลือ (ต้องเติม 0 นำหน้าให้ครบ 9 หลัก)
    for (int i = num->num_chunks - 2; i >= 0; i--) {
        printf("%09u", num->chunks[i]); // %09u คือพิมพ์เลขจำนวนเต็ม 9 หลัก พร้อมเติม 0 ข้างหน้า
    }
}

void BigInt_add(BigInt *result, const BigInt *a, const BigInt *b) {
    BigInt_init(result);
    int max_chunks = (a->num_chunks > b->num_chunks) ? a->num_chunks : b->num_chunks;
    unsigned long long carry = 0;

    for (int i = 0; i < max_chunks || carry; i++) {
        unsigned long long sum = carry;
        if (i < a->num_chunks) sum += a->chunks[i];
        if (i < b->num_chunks) sum += b->chunks[i];

        if (i >= MAX_CHUNKS) {
            fprintf(stderr, "Error: Addition overflowed MAX_CHUNKS\n");
            exit(1);
        }

        result->chunks[i] = sum % BASE;
        carry = sum / BASE;
        result->num_chunks = i + 1;
    }
    // ปรับ num_chunks ถ้า carry ทำให้มีหลักเพิ่ม
    if (result->num_chunks == 0) result->num_chunks = 1; // กรณีผลลัพธ์เป็น 0
}


void BigInt_multiply_by_int(BigInt *result, const BigInt *a, unsigned int val) {
    BigInt_init(result);
    if (val == 0) { // คูณด้วย 0 ได้ 0
        return;
    }

    unsigned long long carry = 0;
    for (int i = 0; i < a->num_chunks || carry; i++) {
        unsigned long long current_val = carry;
        if (i < a->num_chunks) {
            current_val += (unsigned long long)a->chunks[i] * val;
        }

        if (i >= MAX_CHUNKS) {
            fprintf(stderr, "Error: Multiplication by int overflowed MAX_CHUNKS\n");
            exit(1);
        }

        result->chunks[i] = current_val % BASE;
        carry = current_val / BASE;
        result->num_chunks = i + 1;
    }
    // ปรับ num_chunks ถ้า carry ทำให้มีหลักเพิ่ม
    if (result->num_chunks == 0) result->num_chunks = 1;
}

void BigInt_multiply(BigInt *result, const BigInt *a, const BigInt *b) {
    BigInt_init(result); // เริ่มต้นผลลัพธ์เป็น 0

    if ((a->num_chunks == 1 && a->chunks[0] == 0) || (b->num_chunks == 1 && b->chunks[0] == 0)) {
        // ถ้าตัวใดตัวหนึ่งเป็น 0 ผลลัพธ์เป็น 0
        return;
    }

    // num_chunks สูงสุดที่ผลลัพธ์จะเป็นไปได้คือ a->num_chunks + b->num_chunks
    // ตรวจสอบไม่ให้เกิน MAX_CHUNKS
    if (a->num_chunks + b->num_chunks > MAX_CHUNKS) {
        fprintf(stderr, "Error: Multiplication result might overflow MAX_CHUNKS\n");
        // อาจจะต้องจัดการข้อผิดพลาดตรงนี้ หรือเพิ่ม MAX_CHUNKS
        exit(1);
    }

    for (int i = 0; i < a->num_chunks; i++) {
        unsigned long long carry = 0;
        for (int j = 0; j < b->num_chunks || carry; j++) {
            unsigned long long current_product = carry;
            if (j < b->num_chunks) {
                current_product += (unsigned long long)a->chunks[i] * b->chunks[j];
            }

            // เพิ่มผลคูณนี้เข้าไปในตำแหน่งที่ถูกต้องของ result
            // การบวกอาจทำให้เกิด carry ในตำแหน่งถัดไป
            unsigned long long sum_with_existing = result->chunks[i + j] + (current_product % BASE);
            result->chunks[i + j] = sum_with_existing % BASE;
            carry = (current_product / BASE) + (sum_with_existing / BASE);

            // อัปเดต num_chunks ถ้าจำเป็น
            if (i + j + 1 > result->num_chunks) {
                result->num_chunks = i + j + 1;
            }
        }
        // จัดการ carry สุดท้ายหลังจากวนลูป b ครบ
        if (carry > 0) {
            if (i + b->num_chunks >= MAX_CHUNKS) { // ตรวจสอบขอบเขต
                fprintf(stderr, "Error: Multiplication final carry overflowed MAX_CHUNKS\n");
                exit(1);
            }
            unsigned long long final_sum_with_existing = result->chunks[i + b->num_chunks] + carry;
            result->chunks[i + b->num_chunks] = final_sum_with_existing % BASE;
            carry = final_sum_with_existing / BASE;

            if (i + b->num_chunks + 1 > result->num_chunks) {
                 result->num_chunks = i + b->num_chunks + 1;
            }
        }
    }

    // ลบ leading zeros (chunks ที่เป็น 0 ที่อยู่ท้ายสุด แต่ไม่ใช่ตัวเลข 0)
    while (result->num_chunks > 1 && result->chunks[result->num_chunks - 1] == 0) {
        result->num_chunks--;
    }
}


void BigInt_power(BigInt *result, const BigInt *base, int exponent) {
    BigInt_init(result);
    BigInt_set_int(result, 1); // เริ่มต้นผลลัพธ์เป็น 1 (base^0)

    if (exponent == 0) { // อะไรก็ตามยกกำลัง 0 ได้ 1
        return;
    }
    if (base->num_chunks == 1 && base->chunks[0] == 0) { // 0 ยกกำลังอะไร (ที่ไม่ใช่ 0) ได้ 0
        BigInt_init(result);
        return;
    }

    BigInt temp_base;
    BigInt_copy(&temp_base, base);

    // ใช้ Binary Exponentiation (Exponentiation by Squaring) เพื่อประสิทธิภาพ
    while (exponent > 0) {
        if (exponent % 2 == 1) { // ถ้าเลขชี้กำลังเป็นคี่
            BigInt temp_result;
            BigInt_init(&temp_result);
            BigInt_multiply(&temp_result, result, &temp_base);
            BigInt_copy(result, &temp_result);
        }
        // ยกกำลังสองฐาน
        BigInt temp_square_base;
        BigInt_init(&temp_square_base);
        BigInt_multiply(&temp_square_base, &temp_base, &temp_base);
        BigInt_copy(&temp_base, &temp_square_base);

        exponent /= 2;
    }
}
