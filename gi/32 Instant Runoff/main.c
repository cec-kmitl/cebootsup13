#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 20

int main(void)
{
    int n, m;
    char candidates[MAX_CANDIDATES][MAX_NAME_LEN];
    int votes[MAX_CANDIDATES] = {0};
    int voter_choices[MAX_VOTERS][MAX_CANDIDATES];
    int i, j, k;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", candidates[i]);
    }

    // เช็คว่า n และ m ไม่เกินขีดจำกัด
    int valid_ballots = m;
    int is_valid[MAX_VOTERS];
    for (i = 0; i < m; i++) {
        is_valid[i] = 1; // เริ่มต้นทุกบัตรเลือกตั้งเป็น valid
    }

    // นำเข้าการเลือกตั้งของผู้มาใช้เสียง
    for (i = 0; i < m; i++) {
        int used_numbers[MAX_CANDIDATES] = {0};
        int invalid = 0;
        
        for (j = 0; j < n; j++) {
            scanf("%d", &voter_choices[i][j]);
            
            // Check if vote is for a valid candidate (1 to n)
            if (voter_choices[i][j] < 1 || voter_choices[i][j] > n) {
                invalid = 1;
            }
            
            // Check for duplicate votes
            else if (used_numbers[voter_choices[i][j] - 1] == 1) {
                invalid = 1;
            }
            else {
                used_numbers[voter_choices[i][j] - 1] = 1;
            }
            
            // Continue reading input even if ballot is invalid
            voter_choices[i][j]--; // Convert to zero-based index
        }
        
        if (invalid) {
            is_valid[i] = 0;
            valid_ballots--;
        }
    }
    
    int eliminated[MAX_CANDIDATES] = {0};
    int remaining_candidates = n;
    int has_winner = 0;
    
    while (!has_winner && remaining_candidates > 1) {
        // แม่ง
        for (i = 0; i < n; i++) {
            votes[i] = 0;
        }
        
        for (i = 0; i < m; i++) {
            if (!is_valid[i]) continue; // ข้ามบัตรเลือกตั้งที่ไม่ valid
            
            // นับคะแนนเสียงสำหรับผู้สมัครที่ยังไม่ถูกกำจัด
            for (j = 0; j < n; j++) {
                int candidate = voter_choices[i][j];
                if (!eliminated[candidate]) {
                    votes[candidate]++;
                    break;
                }
            }
        }
        
        int majority_threshold = valid_ballots / 2;
        int winner_index = -1;
        for (i = 0; i < n; i++) {
            if (!eliminated[i] && votes[i] > majority_threshold) {
                winner_index = i;
                has_winner = 1;
                break;
            }
        }
        
        // เจอแล้ว
        if (has_winner) {
            printf("Winner: %s\n", candidates[winner_index]);
            break;
        }
        
        // เหี้ย
        int min_votes = valid_ballots + 1;
        for (i = 0; i < n; i++) {
            if (!eliminated[i] && votes[i] < min_votes) {
                min_votes = votes[i];
            }
        }
        
        // fuck
        // กรณีที่มีผู้สมัครที่มีคะแนนเสียงน้อยที่สุดเท่ากัน
        int all_same = 1;
        int first_vote_count = -1;
        
        for (i = 0; i < n; i++) {
            if (!eliminated[i]) {
                if (first_vote_count == -1) {
                    first_vote_count = votes[i];
                } else if (votes[i] != first_vote_count) {
                    all_same = 0;
                    break;
                }
            }
        }
        
        if (all_same && remaining_candidates > 1) {
            // หากมีผู้สมัครที่มีคะแนนเสียงน้อยที่สุดเท่ากัน
            char tie_result[1000] = "";
            for (i = 0; i < n; i++) {
                if (!eliminated[i]) {
                    strcat(tie_result, candidates[i]);
                    strcat(tie_result, " ");
                }
            }
            // ลบช่องว่างสุดท้าย ถ้า tie_result ไม่ว่าง
            if (strlen(tie_result) > 0) {
                tie_result[strlen(tie_result) - 1] = '\0';
            }
            printf("Tie between: %s\n", tie_result);
            has_winner = 1;
            break;
        }
        
        // ดำเนินการกำจัดผู้สมัครที่มีคะแนนเสียงน้อยที่สุด
        for (i = 0; i < n; i++) {
            if (!eliminated[i] && votes[i] == min_votes) {
                eliminated[i] = 1;
                remaining_candidates--;
            }
        }
    }
    
    // เจอกรณีที่ไม่มีผู้ชนะ
    // และเหลือผู้สมัครเพียงคนเดียว
    if (!has_winner && remaining_candidates == 1) {
        for (i = 0; i < n; i++) {
            if (!eliminated[i]) {
                printf("Winner: %s\n", candidates[i]);
                break;
            }
        }
    }

    return 0;
}