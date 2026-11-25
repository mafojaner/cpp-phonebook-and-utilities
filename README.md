# C++ phonebook and console utilities

*Three command-line programs in C++: a phonebook that keeps its contacts between runs, a calendar and time tool built around namespaces, and a three-in-one text and currency utility.*

**Type:** Coursework, object-oriented programming in C++ (2025). Individual work.
**Focus:** Structs, namespaces, enums, reading and writing files, per-field input validation
**Built with:** C++17, standard library only, no third-party dependencies

## Overview

Three separate programs, each with its own `main`. What separates them from a first set of
console exercises is state: the phonebook reads a file when it starts and writes it back
when it changes, and the currency formatter appends every amount it formats. Once a program
remembers things, a missing file, a half-written line and a full list all stop being
hypothetical.

The organisation changes too. Data and the functions that work on it are grouped into
structs, the calendar's two unrelated jobs are separated into namespaces, and months and
weekdays are enums, so a `switch` on a month reads as `case APR:` rather than `case 4:`.

The logic is unchanged from what was submitted. What changed: the files are named for what
they do, three en dashes and a tick character in the console output were replaced with
plain ASCII, because they arrive as mojibake on a Windows console, and the compiled
binaries and the editor folder are left out of this repository.

## The programs

### Phonebook

`src/phonebook.cpp`

A contact list of up to 15 entries held in a fixed-width text file. Add, search by first
name or surname, and list everything with an index.

Each field is validated on its own terms rather than through one general check: names must
be at least two characters and letters only, a phone number must be exactly ten digits, and
an address has to contain both an `@` and a dot. Each prompt loops until it gets something
usable, so a bad entry costs one field and not the whole contact.

Two cases it handles rather than refuses:

- **No data file.** On a first run there is nothing to read. It says so and starts empty
  instead of treating the missing file as an error.
- **A full list.** At 15 contacts it prints what is already stored and offers to delete one
  by its index to make room, so the answer to "it's full" is a choice rather than a dead end.

The file is rewritten in full on every change. At this size that is simpler than editing in
place and there is nothing to gain from being cleverer.

### Calendar and time utilities

`src/calendar.cpp`

Two groups of functions in two namespaces. `TimeUtils` converts a 24-hour time to 12-hour
with AM or PM and reports how many hours are left in the day. `CalendarUtils` gives a
month's name and length and prints the month as a grid under `Su Mo Tu We Th Fr Sa`.

The grid is built by printing blank cells up to the first weekday and then starting a new
line every seventh day, which is the whole of the layout logic.

### Utility toolkit

`src/utility-toolkit.cpp`

A menu of three small tools:

- **Acronym generator.** Takes the first letter of each word and uppercases it. Fewer than
  two words is rejected with an explanation rather than an empty result.
- **Vowel counter.** Counts the five vowels in up to 250 characters, case-insensitively,
  and agrees in number when it reports back ("1 vowel", "2 vowels").
- **Currency formatter.** Rounds to two decimals, inserts thousands separators by walking
  the integer part backwards in threes, prefixes `R`, and appends the result to
  `balance.txt`.

## Building and running

No build system and no dependencies. Each file has its own `main`, so compile them one at a
time:

```bash
g++ -std=c++17 -o phonebook src/phonebook.cpp
./phonebook
```

On Windows with MSVC:

```bat
cl /EHsc /std:c++17 src\phonebook.cpp
```

### The phonebook's data file

The phonebook reads and writes `contactList.dat` in the working directory. It is not in
this repository, because the copy on a machine holds whatever names, numbers and addresses
were typed in while testing. To start from something other than an empty list, copy the
fictional sample over it:

```bash
cp sample-contacts.dat contactList.dat
```

Or just run the program, let it report that there is no list yet, and add contacts.

## Known issues

These are left as they were written rather than quietly corrected. The point of this
repository is to show the work as it stood, and an issue someone can reproduce in a minute
is better stated than hidden.

**Things that change the output**

- **The month grid pads with zeroes after the time tool has run.** `setfill('0')` is set in
  the 12-hour clock function and never reset, and the fill character sticks to the stream.
  Use Time Utilities and then Calendar Utilities in the same session and the days print as
  `01 02 03` instead of ` 1  2  3`. The calendar on its own is correct.
- **The currency formatter accepts a partly numeric entry.** `stod` reads as far as it can
  and stops, so `12abc` is taken as 12 and written to `balance.txt` as `R 12.00`. Only an
  entry with no leading number at all is rejected.
- **February is always 28 days** and there is no leap-year rule. A month number outside
  1 to 12 is named "Invalid" but is still reported as having 31 days.

**Cosmetic and robustness**

- The toolkit's closing line prints `Thank you for using the Utility Toolkit!<< endl`. The
  `<< endl` is inside the quotes instead of after them.
- The phonebook's load message runs together as `1contact(s) found.`, missing a space.
- All three menus loop forever at end of input, for instance when input is piped in or on
  Ctrl+Z. The fail state is cleared and the read retried without first checking whether the
  stream has ended. It does not affect normal interactive use.
- Two functions in the toolkit are never called, left over from an earlier draft: a second
  `generateAcronym` overload and `generateVowel`, which also carries the wrong label in its
  output.

## Skills demonstrated

- Grouping data with the functions that act on it in a struct, and splitting unrelated
  functions into namespaces so the call site says which area it belongs to.
- Enums for months and weekdays, so the code reads in names rather than magic numbers.
- A full round trip to disk: write a fixed-width record, read it back, and cope with the
  file not being there.
- Validation written per field rather than as one blanket check, with each prompt looping
  until the value is usable.
- Recovering `cin` from a fail state instead of letting a bad entry spin the menu.
- Formatting with `<iomanip>`: column widths for a readable table, and thousands separators
  and two decimal places for money.
- Treating a full list as a decision for the user rather than an error.
