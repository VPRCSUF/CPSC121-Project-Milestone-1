# TuffyScheduler Milestone 1

# THIS IS A COPY OF THE READ ME FROM THE ORIGINAL PROJECT MILESTONE.

This is milestone 1 of the [TuffyScheduler Project](https://docs.google.com/document/d/1439ruL-xNEz58-ND_3Li7nthr1om_dwXJ3zQlB42oPI/edit?usp=sharing).

# Requirements
We are creating a program that will help you and other CSUF students select their schedules for the semester. In this milestone, our program will ask the user to provide a file name. The program will load a file using the given file name and check whether it follows the expected format shown below. The program should display on screen either `Valid file` or `Invalid file` after processing it.

## File format
| File format     | Sample file contents|
|-----------------|---------------------|
|< Course name 1 >| CPSC 131            |
|< Location 1 >   | EC 109              |
|< Day 1 >        | MW                  |
|< Start time 1 > | 16:00               |
|< End time 1 >   | 17:15               |
|< Course name 2 >| CPSC 481            |
|< Location 2 >   | CS 408              |
|< Day 2 >        |  MW                 |
|< Start time 2 > | 16:00               |
|< End time 2 >   | 17:15               |
| ...             | ...                 |
|< Course name n >| CPSC 362            |
|< Location n >   | CS 101              |
|< Day 2 >        | MW                  |
|< Start time n > | 8:00                |
|< End time n >   | 9:50                |

### Rules
The program should display an error message whenever it violates any of the rules below. Each rule shows the suggested error message to display. In general, errors use the format shown in the table below.

| Error format             | Sample error                               |
|--------------------------|--------------------------------------------|
| Error: < error message > | Error: End time should be after start time |
|                          | Error: X is an invalid weekly schedule     |

#### File existence
The file should exist, otherwise display an error.

```Error: File does not exist.```

#### Course names
A course name can be any string value. When the program does not detect a course name, it will assume the end of the schedule file.

#### Course location
A course location can be any string value. If the program is unable to retrieve a location, displaly

```Error: Unable to get a location.```

#### Weekly schedule
Only the following values can be used to represent the course's weekly schedule: **M, T, W, H, F, S, MW, MF, TH**

*Take note that H stands for Thursday*

If the program is unable to retreive a weekly schedule, display

```Error: Unable to get a weekly schedule.```

If the weekly schedule uses an invalid day of the week, display

```Error: Invalid weekly schedule symbol < symbol >.```

For example,

```Error: Invalid weekly schedule symbol MWX.```

#### Start time and end time
The start and end times will be represented using military time. Hour values should only go from 0 to 23, while minute values should only go from 0 to 59. The end time should always be greater than the end time.


##### Start time
If the program is unable to retreive a start time, display

```Error: Unable to get a valid start time.```

If the start time is an invalid time, display

```Error: < time > is an invalid start time.```

For example, 

```Error: 45:10 is an invalid start time.```

##### End time

If the program is unable to retreive a end time, display

```Error: Unable to get a valid end time.```

If the end time is an invalid time, display

```Error: < time > is an invalid end time.```

For example, 

```Error: 13:99 is an invalid end time.```

##### Start and end time difference

If the start time is later than the end time , display

```Error: The start time < start time > should happen before the end time < end time >.```

For example, 

```Error: The start time 13:15 should happen before the end time 12:50.```

#### Valid and invalid files
If all rules are satisfied, the program should display

```Valid file```

Otherwise, aside from all errors it should also display

```Invalid file```

# Sample output
Below are samples of the program's output given different cases.

## Valid file
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Valid file.
Thank you for using Tuffy Scheduler.
</pre>

## Start time happens after end time
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Error: The start time 17:15 should happen before the end time 16:00.
Invalid file.
Thank you for using Tuffy Scheduler.
</pre>

## Invalid weekly schedule
<pre>
Welcome to Tuffy Scheduler!
Please enter the file name containing the list of classes: <b>sched.txt</b>
Error: Invalid weekly schedule symbol MX.
Invalid file.
Thank you for using Tuffy Scheduler.
</pre>
