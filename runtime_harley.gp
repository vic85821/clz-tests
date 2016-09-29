reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz-harley time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime_harley.png'

plot  "result.csv" using 1:6 title 'harley' with points pointtype 3


