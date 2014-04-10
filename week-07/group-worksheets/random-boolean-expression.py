#! /usr/bin/env python3

##
# Ben Blazak
# week 7
#
# program to generate random boolean expressions in C++
#


import random


def gen_expression(length):
    prefix_operators = (
            '!', '+', '-',
            '!',      '-',
            '!',      '-',
            '!',
            '!',
            '', '', '', '', '',
            '', '', '', '', '',
            '', '', '', '', '',
            '', '', '', '', '',
            '', '', '', '', '',
            '', '', '', '', '' )
    variables = (
            'a', 'b','c',
            'a', 'b' )
    infix_operators = (
            # - leaving out '/' and '%' so as not to cause division by zero
            #   errors
            '*', '+', '-',
            '<', '>', '<=', '>=', '==', '!=', '&&', '||',
            '<', '>', '<=', '>=', '==', '!=', '&&', '||',
            '<', '>', '<=', '>=', '==', '!=', '&&', '||'  )
    primes = (
            '2', '3', '5', '7', '11', '13', '17', '19', '23', '29' )

    random.seed()

    # base case

    if length == 1:
        po = random.choice(prefix_operators)
        v  = ''
        if random.randint(1,100) <= 95:
            if random.randint(1,100) <= 75:
                v = random.choice(variables)
            else:
                io = random.choice(('/', '%'))
                p1 = random.choice(primes)
                p2 = random.choice(primes)
                v = '(' + p1 + io + p2 + ')'
        else:
            v = gen_expression(1)

        if po == v[0]:
            v = '(' + v + ')'

        return po + v

    # else

    i=0
    output = ''

    if random.randint(1,100) <= 85:
        output = gen_expression(1)
    else:
        sublength = random.randint(1, length)
        i += sublength-1
        output = gen_expression(sublength)

    i+=1

    while i < length:
        po = random.choice(prefix_operators)
        io = random.choice(infix_operators)
        v  = ''
        if random.randint(1,100) <= 80 or length-i <= 1:
            v = gen_expression(1)
        else:
            sublength = random.randint(1, length-i)
            i += sublength-1
            v = gen_expression(sublength)

        if po == v[0]:
            v = '(' + v + ')'

        output += ' ' + io + ' ' + po + v

        i+=1

    po = random.choice(prefix_operators)
    return po + '( ' + output + ' )'


if __name__ == '__main__':
    e = ''

    while not e or len(e) < 80 or len(e) > 97:
        e = gen_expression(random.randint(10,20))

    print(e)

