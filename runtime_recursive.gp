reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz-recursive time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime_recursive.png'

plot  "result.csv" using 1:5 title 'recursive' with points pointtype 3


