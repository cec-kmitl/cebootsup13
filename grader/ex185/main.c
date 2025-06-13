/*
    ::::::::  ::::::::::  ::::::::        :::    ::: ::::    ::::  ::::::::::: ::::::::::: :::
   :+:    :+: :+:        :+:    :+:       :+:   :+:  +:+:+: :+:+:+     :+:         :+:     :+:
   +:+        +:+        +:+              +:+  +:+   +:+ +:+:+ +:+     +:+         +:+     +:+
   +#+        +#++:++#   +#+              +#++:++    +#+  +:+  +#+     +#+         +#+     +#+
   +#+        +#+        +#+              +#+  +#+   +#+       +#+     +#+         +#+     +#+
   #+#    #+# #+#        #+#    #+#       #+#   #+#  #+#       #+#     #+#         #+#     #+#
    ########  ##########  ########        ###    ### ###       ### ###########     ###     ##########
 */

#include <stdio.h>

int main(void)
{
    char sentence[10000];
    int i = 0;
    int is_upper = 1;
    for (char c; scanf("%c", &c) == 1 && c != '\n'; i++)
    {
        sentence[i] = c;
    }

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (is_upper)
        {
            if (sentence[i] >= 97 && sentence[i] <= 122)
            {
                printf("%c", sentence[i] - 32);
            }
            else
            {
                printf("%c", sentence[i]);
            }

            if ((sentence[i] >= 97 && sentence[i] <= 122) || (sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 48 && sentence[i] <= 57))
            {
                is_upper = 0;
            }
        }
        else if (sentence[i] != ' ' && sentence[i] != '_')
        {
            if (sentence[i] >= 65 && sentence[i] <= 90)
            {
                printf("%c", sentence[i] + 32);
            }
            else
            {
                printf("%c", sentence[i]);
            }
        }
        else
        {
            printf("%c", sentence[i]);
            is_upper = 1;
        }
    }
    return 0;
}