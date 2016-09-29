reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime.png'

plot  "result.csv" using 1:2 title 'iterative' with points pointtype 3, \
     "" using 1:3 title 'binary search' with points pointtype 7, \
     "" using 1:4 title 'byte shift' with points pointtype 10, \
     "" using 1:5 title 'recursive' with points pointtype 18, \
     "" using 1:6 title 'harley' with points pointtype 26
