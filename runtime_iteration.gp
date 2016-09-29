reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz-iteration time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime_iteration.png'

plot  "result.csv" using 1:2 title 'iteration' with points pointtype 3

