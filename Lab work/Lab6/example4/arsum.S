.file "arsum.S"
.data
.comm result, 1
.global result
.text
.global compute
compute:
ldi r30, lo8(myarray)
ldi r31, hi8(myarray)
ldi r18, 0
ldi r21, 0
looptest:
ld r22, z+
add r21, r22
inc r18
cpi r18, 10
brlo looptest
out:
sts result, r21
ret
