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
    int fm;
    int a, b;
    scanf("%d", &fm);
    if ((fm < 1) || (fm > 5))
    {
        printf("No Formula");
        return 0;
    }

    scanf("\n%d %d", &a, &b);
    if (fm == 1) printf("Use V = IR\n"), printf("%d V", a * b);
    else if (fm == 2) printf("Use F = ma\n"), printf("%d N", a * b);
    else if (fm == 3) printf("Use P = IV\n"), printf("%d W", a * b);
    else if (fm == 4) printf("Use s = vt\n"), printf("%d m", a * b);
    else if (fm == 5) printf("Use P = mv\n"), printf("%d kg.m/s", a * b);
    return 0;
}