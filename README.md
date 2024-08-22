# Background Info
This a program can be used as a command line tool to perform image binarization. The program even gives the user some options to customize their image binarization!
> **Slow down, what’s a command line?** A command line interface (aka CLI) is a device for text input and output from programs. Portrayed in media as a black screen with green text that hackers use. It’s not as daunting as it seems and you should get familiar with it, because it simplifies a lot of tasks. To learn more, check out: [MIT’s Missing Semester Shell Unit](https://missing.csail.mit.edu/2020/course-shell/), [Intro to the Terminal (for Macs)](https://blog.teamtreehouse.com/introduction-to-the-mac-os-x-command-line), or [Intro to PowerShell (for Windows)](https://programminghistorian.org/en/lessons/intro-to-powershell).

## What is image binarization?
In computer vision, *image binarization*, a.k.a. *thresholding* is the process of taking a grayscale image and converting it into a black and white image. In grayscale images, every pixel represents an intensity value ranging from 0 (black) to 255 (white). In black and white images, every pixel is either 0 or 255. Intensity refers to the brightness of a color, white is the brightest and therefore the most intense, black is the darkest and the least intense. The figure below shows an example of image binarization:

*****Image Binarization Example

## Thresholding IRL
A popular application of (color) thresholding is recreating the effects from Andy Warhol’s Pop Art or Obama’s 2008 Hope poster by Shepard Fairey. While these posters were done by hand, using color thresholding, we can create an algorithm that does the same. Nowadays, there are many online converters that will take an image and convert it to the likes of these iconic pieces. For simplicity’s sake, we’ll be doing the more simple black and white thresholding but you’re welcome to [explore color thresholding](https://www.ecosia.org/search?q=color+thresholding) on your own!

*****Andy Warhol's Marilyn Monroe Pop Art Poster             Obama's 2008 Hope Poster

## Global Thresholding
It’s important to note that pixel values for an image are stored in a matrix. Matrices don’t have to be perfect squares (i.e., 2x2, 3x3, 10x10), and while all most of our examples below are perfect squares, your program should work on images of any dimensions (perfect squares or not).

> **Slow down, what’s a matrix?** You can visualize a matrix as a grid. 2D matrices (aka 2D arrays) are composed of some number of arrays inside another array. To access the element stored at row 2 column 3, you’d say ' myMatrix[2][3] '. Want more info on matrices before continuing? Check out this [Multidimensional Arrays Tutorial](https://www.learncpp.com/cpp-tutorial/multidimensional-arrays/).

The process of image binarization can be done by comparing each pixel within the input image against a predefined threshold T, and deciding whether each individual pixel gets turned white or black. Pixels whose intensity is less than T become black, all others become white.

The algorithm below shows how to binarize an image.

input: Image A (grayscale)
output: Image B (black and white)

calculate global T
for each pixel A[i][j] in A do
    if A[i][j] < T then
        B[i][j] = 0
    else
        B[i][j] = 255
    endif
endfor
The value of T can be automatically calculated by using a function. For example, T can be either 1) the average intensity or 2) the median of all pixels. There are hundreds of different ways for calculating T, often involving statistical measures.

Local Thresholding
While global thresholding uses a constant threshold T for transforming each pixel in an image, the idea behind local thresholding is to transform pixels by only considering the surrounding area, i.e., the local neighborhood of each pixel. The neighborhood of a pixel p is a small matrix of dimensions d x d centered at p. In this case, for each pixel in the image, we are basically calculating a different T. The algorithm below shows how to binarize an image using local thresholding.

input: Image A (grayscale)
output: Image B (black and white)

for each pixel A[i][j] in A do
    calculate T[i][j] using local neighborhood
    if A[i][j] < T[i][j] then
        B[i][j] = 0
    else
        B[i][j] = 255
    endif
endfor
As an illustration, the figure below shows an example of applying local thresholding. In this specific example, the median is what’s as the metric for deciding the new value of a pixel:

Image Binarization

Note that when calculating the neighborhood of pixels at the edges, where the neighborhood is not a perfect fit, we ignore all pixels that fall outside the boundaries of the image. In the illustration above, this is the case of the pixel at position [0,0] highlighted in orange.

Thresholding gone wrong
If you’re paying attention and understanding the concept of thresholding so far, you’ll recognize that the choice of T has strong implications on the quality of the final image. Not all methods of tresholding will work well with all images and understanding what methods work best for your image (or set of images) is crucial.

Below is an example of thresholding gone wrong. Notice how in the last image, two of the objects and part of the third completely disappear:

Example of thresholding removing objects from the image altogether

The implications of these types of miscalculations in computer science are far reaching and can lead to issues such as:

Infra-red light from a soap dispense not recognizing dark-skinned hands (read more).
Facial recognition software not recognizing dark-skinned faces (quick video).
Self-driving cars being more likely to hit folks with dark skin (read more).
The code that you write as computer scientists, (software) engineers, and programmers has real-life consequences that can unintentionally harm people. Keep this in mind as you code because code isn’t objective or siloed.

Your Task
Your goal in this assignment is to develop a command line tool that performs image binarization, given some options (described below) provided by the user. Your program will do both global and local thresholding, depending on the user’s arguments.

For global thresholding, your program should use the median of all pixels for the value of T.
For local thresholding, your program should use adib for value of T[i,j], as calculated by the following formula: T[i,j] = m(i,j) * (1 + k * ((s(i,j)/r)-1)) where:
m is the mean of the local neighborhood centered at pixel (i,j)
s is the standard deviation of the local neighborhood centered at pixel (i,j)
k is 0.2
R is 0.5 * (pmax-pmin)
pmax is the maximum pixel value in the entire image
pmin is the minimum pixel value in the entire image
Below is an image of the formula with better formatting. This formula is from the paper Adaptive document image binarization by Sauvola and PietikaKinen, 2000.

Image Binarization

The options for the user will be provided via the following command line arguments:

<type>      either 'local' or 'global'
<in_fname>  name of the input file
<out_fname> name of the output file
[<size>]    size of the neighborhood
The last argument is optional, and must be provided only when <type> is 'local'. For example, see below for a few examples of how to use your tool. Note that the correct order of command line arguments is very important.

$ ./prog global cover.img cover_glo.img
$ ./prog local cover.img cover_loc_5.img 5
$ ./prog local cover.img cover_loc_7.img 7
$ ./prog local cover.img cover_loc_15.img 15
If you haven’t created C++ programs with command line arguments or need a refresher on how to do so, please read this tutorial and/or watch this video.

The images users will give you and that you will generate will be in the img format, using the .img extension and formatted as follows: Each image is encoded as a matrix of pixel values where each pixel value is a grayscale intensity, an integer ranging from 0 to 255.

When loading or saving images, each img file must be a text file where pixels values are separated by a single whitespace, and organized in n rows and m columns (the image dimensions). For example, here is one file with 10 rows and 8 columns:

121 24 149 1 173 251 10 38 
97 137 153 92 40 93 9 149 
138 136 128 18 66 109 16 138 
185 218 67 3 194 155 186 255 
131 50 188 128 120 193 104 144 
39 109 228 155 131 42 133 93 
75 148 197 137 26 198 0 226 
43 85 167 158 28 207 17 165 
14 150 49 205 79 86 216 8 
88 78 159 41 66 227 84 80 
Note that every pixel value is separated by a single whitespace. There should no trailing whitespaces.

Implementation Note: Within your program, you can represent an image either as a bidimensional array, or as an unidimensional array and design your algorithms accordingly.

We prepared a few conversion scripts that can help you test your program with real-world examples, please refer to this repl.it and feel free to fork it or download it to test your own images.

Requirements
Your submission will be tested and graded by an autograder, for this reason it cannot be stressed enough that your program must exactly follow the assignment specifications:

Use double as the default datatype for the pixels and the terms in all formulas
Use main.cpp as the single filename for your program.
You should receive no warning or error messages upon compilation with the exact following command
 $ g++ -std=c++11 -Wall main.cpp -o prog
Your command line program should use the following arguments, in this exact order:
 <type>      either 'local' or 'global'
 <in_fname>  name of the input file
 <out_fname> name of the output file
 [<size>]    size of the neighborhood
Use functions and classes to abstract your program, per OOP guidelines, but have everything in the same file. Name that file main.cpp
For global thresholding, use the median of all pixels for the value of T.
For local thresholding, use adib formula for value of T[i,j], as defined in the previous section.
BEFORE HANDING IN: Test that your program works by compiling your program with the command in Requirement #3. Successful execution of this command should create an exectuable file named prog, which you should be able to execute using the arguments as outlined in Requirement #4 (example uses below).

$ ./prog global cover.img cover_glo.img
$ ./prog local cover.img cover_loc_5.img 5
$ ./prog local cover.img cover_loc_7.img 7
$ ./prog local cover.img cover_loc_15.img 15
Once you’ve read through the assignment, I encourage you to check out the breakdown video associated with it.

> README.md has been created based on the original assignment description. The original assignment can be found at https://vcc-csc212.github.io/sp21-archive/dd1/#task
