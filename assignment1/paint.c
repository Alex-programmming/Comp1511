// Assignment 1 19T3 COMP1511: CS Paint
// paint.c
//
// This program was written by Haoheng Duan (z5248147)
// on 19/10/2019
//
// Version 1.0.0 (2019-10-08): Assignment released.

#include <stdio.h>

// Note: you may find the square root function (sqrt) from the math
// library useful for drawing ellipses in Stage 3 and Stage 4.
#include <math.h>
#include <stdlib.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4
#define DARK 1
#define GREY 2
#define LIGHT 3


// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);


// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);


// Calculate the distance between two points.
// Note: you will only need this function for the Draw Ellipse command
// in Stages 3 and 4.
double distance(int row1, int col1, int row2, int col2);



// Draw the lines in different degrees
void direction_0(int i, int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour);

void direction_90(int i, int canvas[N_ROWS][N_COLS], int length, int start_row,
 int start_col, int direction, int exit, int colour);

void direction_180(int i, int canvas[N_ROWS][N_COLS], int length, int start_row,
 int start_col, int direction, int exit, int colour);

void direction_270(int i, int canvas[N_ROWS][N_COLS], int length, int start_row,
 int start_col, int direction, int exit, int colour);

void line_direction_45(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void line_direction_135(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void line_direction_225(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void line_direction_315(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);




// Draw the squares in diagonals
void square_direction_45(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void square_direction_135(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void square_direction_225(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);

void square_direction_315(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour);




//Functions that is used in different command to draw different shapes
void drawLine(int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour);

void fillSquare(int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour);

void copyPaste(int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int target_row, int target_col);

void drawEllipse(int canvas[N_ROWS][N_COLS], int colour, int focus_1_row, 
int focus_1_col, int focus_2_row, int focus_2_col, double length2, int fill);





// Main function
int main(void) {
    int canvas[N_ROWS][N_COLS], type, length, start_row, start_col;
    int direction, fill;
    int exit = 0;
    int new_shade, target_row;
    int colour = 0;
    int target_col, focus_1_row, focus_1_col, focus_2_row, focus_2_col;
    double length2;

    clearCanvas(canvas);
    // It is a loop to keep scanning
    // commands until you reach the end of input
    while (scanf("%d", &type) == 1 && exit == 0) {
        // Scan in the rest of the command 
        if (type == 1) {
            scanf("%d %d %d %d", &start_row, &start_col, &length, &direction);   
            drawLine(canvas, length, start_row, start_col, 
            direction, exit, colour);    
        } else if (type == 2) {
            scanf("%d %d %d %d", &start_row, &start_col, &length, &direction);
            fillSquare(canvas, length, start_row, start_col, direction, 
            exit, colour);
        } else if (type == 3) {
            scanf("%d", &new_shade);
            // Save the shade type in this variable
            colour = colour + new_shade;
            if (colour > 4 || colour < 0) {
                // Cancel the previous code in this condition
                colour = colour - new_shade;
            }
        } else if (type == 4) {
            scanf("%d %d %d %d %d %d", &start_row, &start_col, &length, 
            &direction, &target_row, &target_col);
            copyPaste(canvas, length, start_row, start_col, direction, 
            exit, target_row, target_col);
        } else if (type == 0) {
            scanf("%d %d %d %d %lf %d", &focus_1_row, &focus_1_col, 
            &focus_2_row, &focus_2_col, &length2, &fill);
            drawEllipse(canvas, colour, focus_1_row, focus_1_col, 
            focus_2_row, focus_2_col, length2, fill);
        }
    }
    displayCanvas(canvas);
    return 0;
}




// Function that is used to draw lines
void drawLine(int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour) {
    if (length < 0) {
        // Draw the line in the opposite direction if length is less than 0
        length = abs(length);
        direction = direction + 180;
    }
    // Making sure the directions are between 0 and 360 degrees
    if (direction >= 360) {
        direction = direction % 360;
    }
    // Draw the lines in different degrees
    // i is used in loops in the functions that draw lines in different degrees
    int i = 0;
    if (direction == 0) {
        direction_0(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 45) {
        line_direction_45(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 90) {
        direction_90(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 135) {
        line_direction_135(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 180) {
        direction_180(i, canvas, length, start_row, start_col, direction, exit,
         colour);
    } else if (direction == 225) {
        line_direction_225(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 270) {
        direction_270(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 315) {
        line_direction_315(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    }
}




// Function that is used to draw squares
void fillSquare(int canvas[N_ROWS][N_COLS], int length, int start_row,
 int start_col, int direction, int exit, int colour) {
    if (length < 0) {
        // Draw the square in the opposite direction if length is less than 0
        length = abs(length);
        direction = direction + 180;
    }
    // Making sure the directions are between 0 and 360 degrees
    if (direction >= 360) {
        direction = direction % 360;
    }
    // Draw the squares in different degrees
    // i is used in loops in the functions that draw squares in different degrees
    int i = 0;
    if (direction == 0) {
        direction_0(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 45) {
        square_direction_45(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 90) {
        direction_90(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 135) {
        square_direction_135(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 180) {
        direction_180(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 225) {
        square_direction_225(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    } else if (direction == 270) {
        direction_270(i, canvas, length, start_row, start_col, direction, exit, 
        colour);
    } else if (direction == 315) {
        square_direction_315(i, canvas, length, start_row, start_col, direction, 
        exit, colour);
    }
}



// Function that is used to copy and paste
void copyPaste(int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int target_row, int target_col) {
    // This array is temporary and is used to save what has been copied
    int copy[length][length];
    int i = 0;
    // Copy and paste them in different directions
    if (direction == 45) {
        // copy
        // Making sure that any part of the copying will not go 
        // outside of the canvas
        if (start_row - length + 1 < 0 || start_col + length - 1 > 35) {
            exit = 1;
        } else {
            // Making sure that copying starts in the canvas
            while (i < length && start_col >= 0 && start_col <= 35 && 
            start_row >= 0 && start_row <= 19) {
                int j = 0;
                while (j < length) {
                    // Loop and save the state of the canvas in the 
                    // temporary array
                    copy[i][j] = canvas[start_row][start_col];
                    //right
                    start_col++;
                    j++;
                }
                i++;
                //up
                start_row--;
                // The start column will go back to the original column and 
                // loop again
                start_col = start_col - length;
            }
            i = 0;
            // paste
            // Making sure that any part of the pasting will not go outside 
            // of the canvas
            if (target_row - length + 1 < 0 || target_col + length - 1 > 35) {
                exit = 1;
            } else {
                // Making sure that pasting starts in the canvas
                while (i < length && target_col >= 0 && target_col <= 35 && 
                target_row >= 0 && target_row <= 19) {
                    int j = 0;
                    while (j < length) {
                        // Loop and save the state of the temporary array 
                        // in the canvas
                        canvas[target_row][target_col] = copy[i][j];
                        target_col++;
                        j++;
                    }
                    // The target column will go back to the original column
                    // and loop again
                    target_col = target_col - length;
                    target_row--;
                    i++;
                }
            }
        }
    } else if (direction == 135) {
        if (start_row + length - 1 > 19 || start_col + length - 1 > 35) {
            exit = 1;
        } else {
            while (i < length && start_col >= 0 && start_col <= 35 && 
            start_row >= 0 && start_row <= 19) {
                int j = 0;
                while (j < length) {
                    copy[i][j] = canvas[start_row][start_col];
                    start_col++;
                    j++;
                }
                i++;
                start_row++;
                start_col = start_col - length;
            }
            i = 0;
            if (target_row + length - 1 > 19 || target_col + length - 1 > 35) {
                exit = 1;
            } else {
                while (i < length && target_col >= 0 && target_col <= 35 && 
                target_row >= 0 && target_row <= 19) {
                    int j = 0;
                    while (j < length) {
                        canvas[target_row][target_col] = copy[i][j];
                        target_col++;
                        j++;
                    }
                    target_col = target_col - length;
                    target_row++;
                    i++;
                }
            }
        }
    } else if (direction == 225) {
        if (start_row + length - 1 > 19 || start_col - length + 1 < 0) {
            exit = 1;
        } else {
            while (i < length && start_col >= 0 && start_col <= 35 && 
            start_row >= 0 && start_row <= 19) {
                int j = 0;
                while (j < length) {
                    copy[i][j] = canvas[start_row][start_col];
                    start_col--;
                    j++;
                }
                i++;
                start_row++;
                start_col = start_col + length;
            }
            i = 0;
            if (target_row + length - 1 > 19 || target_col - length + 1 < 0) {
                exit = 1;
            } else {
                while (i < length && target_col >= 0 && target_col <= 35 && 
                target_row >= 0 && target_row <= 19) {
                    int j = 0;
                    while (j < length) {
                        canvas[target_row][target_col] = copy[i][j];
                        target_col--;
                        j++;
                    }
                    target_col = target_col + length;
                    target_row++;
                    i++;
                }
            }
        }
    } else if (direction == 315) {
        if (start_row - length + 1 < 0 || start_col - length + 1 < 0) {
            exit = 1;
        } else {
            while (i < length && start_col >= 0 && start_col <= 35 && 
            start_row >= 0 && start_row <= 19) {
                int j = 0;
                while (j < length) {
                    copy[i][j] = canvas[start_row][start_col];
                    start_col--;
                    j++;
                }
                i++;
                start_row--;
                start_col = start_col + length;
            }
            i = 0;
            if (target_row - length + 1 < 0 || target_col - length + 1 < 0) {
                exit = 1;
            } else {
                while (i < length && target_col >= 0 && target_col <= 35 && 
                target_row >= 0 && target_row <= 19) {
                    int j = 0;
                    while (j < length) {
                        canvas[target_row][target_col] = copy[i][j];
                        target_col--;
                        j++;
                    }
                    target_col = target_col + length;
                    target_row--;
                    i++;
                }
            }
        }
    }
}




// Function that is used to draw ellipse
void drawEllipse(int canvas[N_ROWS][N_COLS], int colour, int focus_1_row, 
int focus_1_col, int focus_2_row, int focus_2_col, double length2, int fill) {
    if (fill != 0) {
        // fill in the ellipse
        // Use the array to loop through all the canvas and find the 
        // points that meet the requirements
        int i = 0;
        while (i < N_ROWS) {
            int j = 0;
            while (j < N_COLS) {
                if (distance(i, j, focus_1_row, focus_1_col) + distance(i, j, 
                focus_2_row, focus_2_col) <= 2 * length2) {
                    canvas[i][j] = colour;
                }
                j++;
            }
            i++;
        }
    } else if (fill == 0) {
        // only draw the outline of the ellipse.
        // Use the array to loop through all the canvas and find the points 
        // that meet the requirements
        int i = 0;
        while (i < N_ROWS) {
            int j = 0;
            while (j < N_COLS) {
                if (distance(i, j, focus_1_row, focus_1_col) + 
                distance(i, j, focus_2_row, focus_2_col) <= 2 * length2 ) {
                    // Select points in ellipse that is at the 
                    // boundary(find the points next to boundary points)
                    if (distance(i, j + 1, focus_1_row, focus_1_col) + 
                    distance(i, j + 1, focus_2_row, focus_2_col) > 2 * length2) 
                    {
                        // change the colour
                        canvas[i][j] = colour;
                    } else if (distance(i, j - 1, focus_1_row, focus_1_col) + 
                    distance(i, j - 1, focus_2_row, focus_2_col) > 2 * length2) 
                    {
                        canvas[i][j] = colour;
                    } else if (distance(i + 1, j, focus_1_row, focus_1_col) + 
                    distance(i + 1, j, focus_2_row, focus_2_col) > 2 * length2) 
                    {
                        canvas[i][j] = colour;
                    } else if (distance(i - 1, j, focus_1_row, focus_1_col) + 
                    distance(i - 1, j, focus_2_row, focus_2_col) > 2 * length2) 
                    {
                        canvas[i][j] = colour;
                    }
                }
                j++;
            }
            i++;
        }
    }
}



// Draw the lines in different degrees
void direction_0(int i, int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour) {
    // Making sure that the line will not go outside of the canvas
    if (start_row - length + 1 < 0) {
        exit = 1;
    } else {
        // Making sure that drawing starts in the canvas
        // Loop to draw a line
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            //up
            start_row--;
            i++;
        }
    }
}

void direction_90(int i, int canvas[N_ROWS][N_COLS], int length, int start_row, 
int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_col + length - 1 > 35) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_col++;
            i++;
        }
    }
}

void direction_180(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row + length - 1 > 19) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 
        && start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_row++;
            i++;
        }
    }
}

void direction_270(int i, int canvas[N_ROWS][N_COLS], int length,
 int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_col - length + 1 < 0) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_col--;
            i++;
        }
    }
}

void line_direction_45(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row - length + 1 < 0 || start_col + length - 1 > 35) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            //right
            start_col++;
            //up
            start_row--;
            i++;
        }
    }
}

void line_direction_135(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row + length - 1 > 19 || start_col + length - 1 > 35) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_col++;
            start_row++;
            i++;
        }
    }
}


void line_direction_225(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row + length - 1 > 19 || start_col - length + 1 < 0) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_col--;
            start_row++;
            i++;
        }
    }
}


void line_direction_315(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row - length + 1 < 0 || start_col - length + 1 < 0) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            canvas[start_row][start_col] = BLACK + colour;
            start_col--;
            start_row--;
            i++;
        }
    }
}



// Draw the squares in diagonals
void square_direction_45(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    // Making sure that the square will not go outside of the canvas
    if (start_row - length + 1 < 0 || start_col + length - 1 > 35) {
        exit = 1;
    } else {
        // Making sure that drawing starts in the canvas
        // Loop to draw a square
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            int j = 0;
            while (j < length) {
                canvas[start_row][start_col] = BLACK + colour;
                //right
                start_col++;
                j++;
            }
            // The start column will go back to the original column and 
            // loop again
            start_col = start_col - length;
            //up
            start_row--;
            i++;
        }
    }
}

void square_direction_135(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row + length - 1 > 19 || start_col + length - 1 > 35) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            int j = 0;
            while (j < length) {
                canvas[start_row][start_col] = BLACK + colour;
                start_col++;
                j++;
            }
            start_col = start_col - length;
            start_row++;
            i++;
        }
    }
}

void square_direction_225(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour){
    i = 0;
    if (start_row + length - 1 > 19 || start_col - length + 1 < 0) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            int j = 0;
            while (j < length) {
                canvas[start_row][start_col] = BLACK + colour;
                start_col--;
                j++;
            }
            start_col = start_col + length;
            start_row++;
            i++;
        }
    }
}

void square_direction_315(int i, int canvas[N_ROWS][N_COLS], int length, 
int start_row, int start_col, int direction, int exit, int colour) {
    i = 0;
    if (start_row - length + 1 < 0 || start_col - length + 1 < 0) {
        exit = 1;
    } else {
        while (i < length && start_col >= 0 && start_col <= 35 && 
        start_row >= 0 && start_row <= 19) {
            int j = 0;
            while (j < length) {
                canvas[start_row][start_col] = BLACK + colour;
                start_col--;
                j++;
            }
            start_col = start_col + length;
            start_row--;
            i++;
        }
    }
}



// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}


// Calculate the distance between two points (row1, col1) and (row2, col2).
// Note: you will only need this function for the Draw Ellipse command
// in Stages 3 and 4.
double distance(int row1, int col1, int row2, int col2) {
    int row_dist = row2 - row1;
    int col_dist = col2 - col1;
    return sqrt((row_dist * row_dist) + (col_dist * col_dist));
}
