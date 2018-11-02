cmake_minimum_required(VERSION 3.3)
project(projecteuler)

add_executable(30-fifth-powers 30-fifth-powers.c)
target_link_libraries(30-fifth-powers m)

add_executable(31-coins 31-coins.c)

add_executable(32-pandigital-products 
               32-pandigital.c 
               digits.c 
               intlist.c 
               numbers.c 
               errormessages.c)
target_link_libraries(32-pandigital-products m)

add_executable(33-digit-cancelling-fractions
               33-digit-cancelling-fractions.c
               fractions.c
               numbers.c
               digits.c
               errormessages.c)
target_link_libraries(33-digit-cancelling-fractions m)

add_executable(34-digit-factorials
               34-digit-factorials.c
               digits.c
               numbers.c
               errormessages.c)
target_link_libraries(34-digit-factorials m)

add_executable(35-circular-primes
               35-circular-primes.c
               numbers.c
               digits.c
               primelist.c
               errormessages.c)
target_link_libraries(35-circular-primes m)

add_executable(36-double-base-palindromes
               36-double-base-palindromes.c
               digits.c
               numbers.c
               errormessages.c
               intlist.c)
target_link_libraries(36-double-base-palindromes m)

add_executable(37-truncable-primes
               37-truncable-primes.c
               digits.c
               numbers.c
               errormessages.c
               primelist.c)
target_link_libraries(37-truncable-primes m)

add_executable(38-pandigital-multiples
               38-pandigital-multiples.c
               digits.c
               numbers.c
               errormessages.c)
target_link_libraries(38-pandigital-multiples m)

add_executable(41-pandigital-prime
               41-pandigital-prime.c
               digits.c
               numbers.c
               errormessages.c
               primelist.c)
target_link_libraries(41-pandigital-prime m)