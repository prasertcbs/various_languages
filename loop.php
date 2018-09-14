<?php
function loop1() {
    for ($i = 1; $i <= 10; $i++) {
        echo $i . '<br/>';
    }
}

function loop2() {
    for ($i = 1; $i <= 10; $i += 3) {
        echo $i . '<br/>';
    }
}

function loop3() {
    for ($i = 5; $i >= 1; $i--) {
        for ($j = 1; $j <= $i; $j++) {
            echo $j . ' ';
        }
        echo '<br/>';
    }
}

//loop2();

function sum() {
    $total = 0;
    for ($i = 1; $i <= 5; $i += 2) {
        echo "i = " . $i . '<br/>';
        //$total = $total + $i;
        $total += $i;
        //echo $i . '<br/>';
    }
    return $total;
}

function countDown() {
    for ($i = 10; $i >= 0; $i--) {
        echo $i . '<br/>';
    }
}

//echo countDown();
//loop2();
//countDown();
loop3();
?>