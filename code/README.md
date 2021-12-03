## code
Here lies the codes that supplements the project.  
# ascii.cpp
This is the main file that is used to visualize the grids in the pixels.  
By default, the grid size is 10x10 (and should be maximum of 10x10 due to how the output format works).  
However, this size can be changed by redefining GRID_LENGTH and GRID_WIDTH.  
Usage: ./ascii(.exe for windows) (-l|-r "Raw data")  
By default, ./ascii will open a blank grid, while -l or -r would load the data.  
-l would load the file for edit, while -r would be read-only mode.  
# BitFlip  
Usage: ./bitflip "Raw data" "pixel,location"  
This file helps the user flips the data in the current raw data pixels.  
# BitLine  
Usage: ./bitline "Raw data" "row,number"  
This file helps flips the data in the whole row into whichever pixel type you want, either 0 or 1.
