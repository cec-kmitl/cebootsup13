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
    char str1[100], str2[100], out[200];
    int idx = 0;
    scanf("%s\n%s", str1, str2);
    for (int i = 0; str1[i]; i++)
    {
        int j;
        for (j = 0; j < idx; j++) if (out[j] == str1[i]) break;
        if (j == idx) out[idx++] = str1[i];
    }

    for (int i = 0; str2[i]; i++)
    {
        int j, k;
        for (j = 0; str1[j]; j++) if (str1[j] == str2[i]) break;
        if (str1[j]) continue;
        for (k = 0; k < idx; k++) if (out[k] == str2[i]) break;
        if (k == idx) out[idx++] = str2[i];
    }
    out[idx] = '\0';
    printf("%s", out);
    return 0;
}