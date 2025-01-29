/*
 * Part1.h
 *
 * Created: 2025-01-23 13:15:00
 *  Author: albin
 */ 

#ifndef PART1_H_INCLUDED
#define PART1_H_INCLUDED
#include <stdbool.h>

void LCDinit();
void writeChar(char ch, int pos);
void writeLong(long i);
bool is_prime(long i);
void prime();
#endif