--------------------------------------------------------
# MNXB11-2023-homework4
--------------------------------------------------------
### Author: Florido Paganelli florido.paganelli@hep.lu.se
###         Lund University
--------------------------------------------------------

## The problem

We want to download a list of files and divide them into two directories
`PDF` and `notPDF` depending on whether the downloaded file is a 
pdf of not (see slides about Datasets for a better understanding of formats).

There is no limit to the amount of files in the list.

If a file is not downloadable, it must be skipped, whatever temporary file
produced to download that file must be removed.

## A solution

In this homework you're required to write a bash script called `homework4.sh` 
that does the following: 

  1. Takes as input a list of URLs to some websites (there is no limit to how many)  
  2. Downloads each URL into an `input_N` file using `wget`, where N is
     the position of the link in the list, starting from 1  
  3. Checks whether the downloaded file is a pdf or not.  
     3.1. If it is a PDF, moves it into a `PDF` folder and adds the 
    `.pdf` extension to the filename, for example `PDF/input_1.pdf`  
     3.2. If it is **not** a PDF, moves it into a `notPDF` folder
          for example: `notPDF/input_1`

If any of the above steps encounters an error, prints the error on screen
and in some case exit with error exit code when it is not possible to 
continue.

If the user forgets the parameters, the script should print an error and
exit with error code.

The script must log the output of `wget` inside a logfile called `wget.log`

## How to proceed

Rename and edit the provided pseudocode file `homework4.sh.pseudocode`
as `homework4.sh` and substitute the lines `YOUR_CODE_HERE` with the code that 
accomplishes the requested task. To start, follow the instructions below.

### Prepare for the homework

1. Copy the homework directory to your home directory on Cosmos using git
   and the existing local working copy of the repository for Tutorial 4.
   If you do not have such repository please follow the instructions at
   slide 30 of tutorial 4.

```console
# Access the git repository
cd ~/git/MNXB11-BASH
```
2. Update your working copy with the latest changes in the repository:

```console
git pull
```

3. Access your MNXB11-homework local copy:

```console
cd ~/git/MNXB11-homework
```

4. Create and checkout a development branch for your homework:

```console
git checkout -b dev-homework4
```

5. create a homework4 directory: 

```console
mkdir homework4
```

6. Copy the content of the `MNXB11-BASH/homework4` folder inside your 
newly created branch this way:

```console
cp -ar ~/git/MNXB11-BASH/homework4/* ~/git/MNXB11-homework/homework4/
```

7. Access the code subfolder:

```console
cd homework4/code
```

8. rename `homework4.sh.pseudocode` to `homework4.sh`

```console
mv homework4.sh.pseudocode homework4.sh
```

9. Add, commit your initial state of `homework4.sh` and commit your development branch:

```
git add homework4.sh
git commit -m 'Initial commit for homework4'
git push origin dev-homework4
```

10. You can now follow the section "How to progress"

  - To test your code, don't forget to make `homework4.sh` executable:

```console
chmod +x homework4.sh
```

While coding you may assume that any files or folders should be created 
in the current directory where the script is.
However, correction will be done on a different computer than COSMOS,
so it is **mandatory** to use **relative paths** to reference such folder.
Read about relative paths in the manual and in Tutorial 2.
   
### How to progress 

The file `homework4.sh.pseudocode` contains pseudocode written by the
teacher to help you progressing and increasing your knowledge of bash.
It consists of several tasks and their description.

You are requested to write code where the text says `YOUR_CODE_HERE`

**Delete** the text `YOUR_CODE_HERE` and start writing your own code
according to the exercise request. There is no limit in how much you 
write as long as it fulfils the requirements of the exercise.

You can do the exercises one by one and test the result against the
files in the `output_examples/` folder (see folder structure below)

If you are annoyed by the error messages caused by lines that you did 
not yet edit, use the `#` symbol to comment out lines so that bash will 
ignore them as we've seen in the examples in Tutorial 4.

### Folder structure

the `homework4` structure is as follows:

```console
.
├── code  # contains code you have to modify
│   └── homework4.sh.pseudocode # the pseudocode file you need to edit
├── README.md # this document
└── output_examples # the example output for the exercise
    ├── no_parameters # The output the code should generate if the user forgets to add any parameter, i.e.
    │                          ./homework4.sh
    ├── all_parameters_right # The output the code should generate if the user runs the script with all parameters 
    |                          and wget can download all the files:
    │                          ./homework4.sh ./homework4.sh 'https://canvas.education.lu.se/files/4047200/download?download_frd=1' 'https://github.com/floridop/MNXB11-BASH/blob/main/README.md'  http://www.hep.lu.se
    └── some_downloads_fail # The output the code should generate if the 
                              user runs the script writing incorrect URLs,
                              or URLs to files that do not exist or 
                              cannot be downloaded.
                               ./homework4.sh 'https://canvas.education.lu.se/files/4047200/download?download_frd=1' 'https://github.com/floridop/MNXB11-BASH/blob/main/unexistingfile'  http://unexistingaddress.lu.se
```

In addition each folder contains:

  - `command_to_run` the command to run to replicate each example scenario
  - `output` the output your script is supposed to print on screen
  - `wget.log` generated by `wget`
  - the folders `PDF` and `notPDF` and their contents depending on each scenario above.
    
You should test your code with the exact input provided in the `command_to_run` file.

### Tracking your progress

In this homework the best way to track your progress is to use the debug mode
(see Tutorial 4 Slide 42) or use `echo` to printout the content of a 
certain variable to cross check that it contains what you expect.

If you do not want to run the whole script but you want it to stop at
any point, you can simply add an `exit 0` statement at the point you want the 
script to stop. Remember everything is executed from top to bottom of the script.

Check the folder `output_examples/` to compare what the files you generate should look like.

The `output` files in each example folder show you what the program should print when 
called on selected inputs. Check the section Folder Structure above.

You can save your output and compare files using using `diff` or `meld`. 

More about this is in a separate section below. `meld` is described in the
git tutorial.

#### Tips to check the script results

You can use the `diff` tool to compare the differences between the 
output of your script and the outputs in `output_examples/`.

```console
diff fileA fileB
```

The `diff` tool prints out differences between a `fileA` and `fileB`,
and does not print the things the two files have in common.

Some info about diff here:

<https://www.computerhope.com/unix/udiff.htm>

For the homework, here's what you can do for example for scenario `some_downloads_fail`:

1) Use exactly the commands in `output_examples/some_downloads_fail/command_to_run` and save to file the output of your script to a file called `myoutput`:

```console
   ./homework4.sh ./homework4.sh 'https://canvas.education.lu.se/files/4047200/download?download_frd=1' 'https://github.com/floridop/MNXB11-BASH/blob/main/unexistingfile'  http://unexistingaddress.lu.se &> myoutput
```

2) Run diff 

```console
   diff myoutput ../output_examples/some_downloads_fail/output
```

Some outputs will differ by definition, for example, `wget` prints out
the date when it downloads things

However, the lines about filetype should **NOT** differ, that means that `diff`
should not print them out.

You can make the result scrollable by using `less` (exit by pressing `q`):


```console
   diff myoutput ../output_examples/some_downloads_fail/output | less
```

If you want a graphical comparison tool, you can use `meld` described in
the additional material in the git tutorial


## Grades

The `homework4.sh.pseudocode` file contains a description of how the 
homework is graded. 

## Submission

Send me a git HTTPS:// URL of your branch `dev-homework4` **on Canvas**.
If you have problems with this contact me.
No other submission method will be accepted.

To download your homework I will run the following:

```console
git clone YOUR_GIT_HTTPS_URL
git checkout dev-homework4
```
and run various tests against `./homework4.sh`

Good luck!
