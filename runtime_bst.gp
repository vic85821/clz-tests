reset
set xlabel 'N'
set ylabel 'time(sec)'
set style fill solid
set key left
set grid
set title 'clz-binary-search time'
set term png enhanced font 'Verdana,10'
set datafile separator ","
set output 'runtime_binary_search.png'

plot  "result.csv" using 1:3 title 'binary search' with points pointtype 3


