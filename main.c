#include <stdio.h>
#include <stdbool.h>

/**
 * Copyright 2022 amanthanvi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

int get_number_of_digits(int num)
{
    int num_digits = 0;

    while (num != 0)
    {
        num /= 10;
        num_digits++;
    }

    return num_digits;
}

bool is_armstrong(int num)
{
    int num_digits = get_number_of_digits(num);
    int sum = 0, i = 0, curr_num = 0;

    for (i = num; i != 0; i /= 10)
    {
        int curr_num = i % 10, curr_exp = 1, j = 0;

        for (; j < num_digits; j++)
            curr_exp *= curr_num;

        sum += curr_exp;
    }

    return sum == num;
}

int main(void)
{
    int input_num = 0, result = 0;

    printf("Enter a number to see if it's an Armstrong number: ");
    scanf("%d", &input_num);

    if (input_num < 0)
    {
        printf("Negative numbers are not supported!");
        return -1;
    }

    printf("Is %d an Armstrong number?: %s\n", input_num,
           is_armstrong(input_num) ? "Yes" : "No");

    return 0;
}