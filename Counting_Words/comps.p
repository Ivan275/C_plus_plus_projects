#!/usr/bin/gnuplot
# A script for plotting the output from words in gnuplot
# Writes the plot into average_comps.png
set terminal png
set output 'average_comps.png'
set xlabel "Word length"
set ylabel "Comparisons"
plot  "average_comps.txt" using 1:2 title 'Comparisons' with line