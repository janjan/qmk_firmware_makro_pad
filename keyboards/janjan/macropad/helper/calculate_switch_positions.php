<!-- just a lazu script to print the switch positions for the led config -->

<?php

function printxy($xidx, $yidx): string
{
    $NUMBER_OF_COLS = 4;
    $NUMBER_OF_ROWS = 5;
    $x = round(224 / ($NUMBER_OF_COLS - 1) * $xidx);
    $y = round(64 / ($NUMBER_OF_ROWS - 1) * $yidx);

    return "{ $x, $y }";
}


$x = [0,1,2,3];
$y = [0,1,2,3,4];

foreach ($y as $yidx => $yvalue) {
    foreach ($x as $xidx => $xvalue) {
        echo printxy($xvalue, $yvalue) . ', ';
    }

    echo PHP_EOL;
}
