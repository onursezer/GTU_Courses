li        $t0, 4
li        $t1, 3
li        $t2, 12

li        $t3, 3
mult      $t1, $t3
mflo      $t4

sub       $t5, $t0, $t4
move      $t1, $t5

li        $t6, 3
div       $t0, $t6
mflo      $t7

mult      $t7, $t1
mflo      $t8

li        $t3, 21
add       $t3, $t8, $t3
move      $t2, $t3

move      $a0, $t2
li        $v0, 1
syscall
