#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char search[100];
    // รับข้อมูลจากผู้ใช้

    fgets(sentence, sizeof(sentence), stdin); //บรรทัดนี้เป็นการรับข้อมูล input อีกรูปแบบหนึ่งที่สามารถรับข้อความยาวๆ ที่มีช่องว่างคั่นได้
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0; // ลบ newline ออกจาก search

    // ค้นหาคำในประโยค
    char *found = strstr(sentence, search);
    if (found) {
        // ถ้าพบคำ ให้แสดงตำแหน่งที่พบ 
        // input "CE Boost UP 13" \n "13"
        // output Found '13' at word position: 4

        // int position = found - sentence; // หาตำแหน่งโดยจำนวนคำ
        int position = 1;
        char *temp = sentence;
        while (temp < found) {
            if (*temp == ' ' || *temp == '\0') {
                position++;
            }
            temp++;
        }
        // แสดงผลลัพธ์ 
        printf("Found '%s' at word position: %d\n", search, position);
    } else {
        // ถ้าไม่พบคำ ให้แสดงข้อความ
        printf("Word '%s' not found in the sentence.\n", search);
    }
}