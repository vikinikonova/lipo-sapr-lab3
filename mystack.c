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
#include "mystack.h"

void my_stack_init(my_stack* stack, size_t size)
{
    stack->n_size = size;
    stack->n_count = 0;
    stack->n = calloc(stack->n_size, sizeof(int));
}

void my_stack_done(my_stack* stack)
{
    stack->n_size = 0;
    stack->n_count = 0;
    free(stack->n);
}

void my_stack_clean(my_stack* stack)
{
    stack->n_count = 0;
}

int my_stack_count(my_stack* stack)
{
    return stack->n_count;
}

void my_stack_push(my_stack* stack, int value)
{
    if (stack->n_count >= stack->n_size) {
        return;
    }
    stack->n[stack->n_count++] = value;
}

int my_stack_pull(my_stack* stack)
{
    if (stack->n_count == 0) {
        return -1;
    }
    return stack->n[--stack->n_count];
}

int my_stack_top(my_stack* stack)
{
    if (stack->n_count == 0) {
        return -1;
    }
    return stack->n[stack->n_count];
}

int my_stack_is_empty(my_stack* stack)
{
    return stack->n_count == 0;
}

int my_stack_is_full(my_stack* stack)
{
    return stack->n_count >= stack->n_size;
}