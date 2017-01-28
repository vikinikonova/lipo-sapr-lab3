/*
This file is part of Reverse Notation Calc.

    Reverse Notation Calc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdlib.h>
#include "chstack.h"

void char_stack_init(ch_stack* stack, size_t size)
{
    stack->ch_size = size;
    stack->ch_count = 0;
    stack->ch = calloc(stack->ch_size, sizeof(char));
}

void char_stack_done(ch_stack* stack)
{
    stack->ch_size = 0;
    stack->ch_count = 0;
    free(stack->ch);
}

void char_stack_clean(ch_stack* stack)
{
    stack->ch_count = 0;
}

int char_stack_count(ch_stack* stack)
{
    return stack->ch_count;
}

void char_stack_push(ch_stack* stack, char value)
{
    if (stack->ch_count >= stack->ch_size) {
        return;
    }
    stack->ch[stack->ch_count++] = value;
}

char char_stack_pull(ch_stack* stack)
{
    if (stack->ch_count == 0) {
        return -1;
    }
    return stack->ch[--stack->ch_count];
}

char char_stack_get_deep(ch_stack* stack, int index)
{
    if (stack->ch_count == 0 || index < 0 || stack->ch_count < index) {
        return -1;
    }
    return stack->ch[index];
}

int char_stack_top(ch_stack* stack)
{
    if (stack->ch_count == 0) {
        return -1;
    }
    return stack->ch[stack->ch_count];
}

int char_stack_is_empty(ch_stack* stack)
{
    return stack->ch_count == 0;
}

int char_stack_is_full(ch_stack* stack)
{
    return stack->ch_count >= stack->ch_size;
}