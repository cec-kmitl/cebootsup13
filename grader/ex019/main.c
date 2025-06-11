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
#include <string.h>

int main()
{
   char sentence[1001], word[1001];
   fgets(sentence, 1001, stdin);
   scanf("%s", word);

   sentence[strcspn(sentence, "\n")] = 0;

   int pos = 0;
   char *token = strtok(sentence, " ");
   while (token)
   {
      pos++;
      if (strcmp(token, word) == 0)
      {
         printf("Found '%s' at word position: %d\n", word, pos);
         return 0;
      }
      token = strtok(NULL, " ");
   }
   printf("Word '%s' not found in the sentence.", word);
   return 0;
}