reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz-byteshift time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime_byteshift.png'

plot  "result.csv" using 1:4 title 'byte shift' with points pointtype 3


