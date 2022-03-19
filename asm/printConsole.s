.data 
str:    .string   "A string"
newline:    .string   "\n"

.text
    la a0, str
    li a7, 4
    ecall

    jal printNewline

    jal exit

printNewline:
    la a0, newline
    li a7, 4
    ecall
    jr x1

exit:
    li a7, 10
    ecall