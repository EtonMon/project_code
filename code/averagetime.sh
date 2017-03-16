#!/bin/bash

#Prompts user to input dictionary and grid filenames
echo Enter dictionary file name:
read dict
echo Enter grid file name:
read grid

#Runs wordPuzzle with given dictionary and grid filenames 5 times
#Runtimes are stored in variables
running_time1=`./a.out ${dict} ${grid} | tail -1`
running_time2=`./a.out ${dict} ${grid} | tail -1`
running_time3=`./a.out ${dict} ${grid} | tail -1`
running_time4=`./a.out ${dict} ${grid} | tail -1`
running_time5=`./a.out ${dict} ${grid} | tail -1`

#Average of runtimes are calculated and stored in avg_time variable
avg_time=$(((${running_time1}+${running_time2}+${running_time3}+${running_time4}+${running_time5})/5))

#Print average runtime
echo Average run time after 5 runs: ${avg_time} ms
