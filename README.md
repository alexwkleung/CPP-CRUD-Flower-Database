# C++ CRUD Flower Database
![](img/1.png)
![](img/2.png)

A rewrite of my C++ CRUD Flower Database project. 

This is a simple CRUD (Create, Read, Update, Delete) app in the CLI that uses a flat-file database.

# Database Options

**1. Add a new entry to the database**

Add a new entry to the database, i.e., `Flower`.

If `Flower` already exists in the database, then it will output `Flower exists in the database. Try again.` and will prompt you to enter another entry to add.

If `Flower` does not exist in the database, then it will be added.

**2. Update an entry in the database**

Enter an entry to update, i.e., `Lavender`.

If `Lavender` is not found in the database, then it will output `Lavender not found in the database. Try again.` and wiil prompt you to enter another entry to update.

If `Lavender` is found in the database, then it will prompt you to enter the updated string in place of `Lavender`, i.e., `Lav`.

Then it will output `Updated entry Lavender in the database! (Lavender --> Lav)` explaining that the entry has been updated.

**3. Delete an entry in the database**

Enter an entry to delete from the database, i.e., `Daisy`.

If `Daisy` is not found in the database, then it will output `Daisy not found in the database. Try again.` and will prompt you to enter another entry to delete.

If `Daisy` is found in the database, then it will output `Deleted Daisy from the database!` explaining that the entry has been deleted.

**4. Search the database** 

Search for an entry, i.e., `Iris`

If `Iris` is not found in the database, then it will output `Iris not found in the database. Try again.` and will prompt you to enter another entry to search.

If `Iris` is found in the database, then it will output 

`Entry found: Iris`

`At index (sorted vector; 0-based): 13`

"Entry found" is the inputted entry that exists in the database, and "At index (sorted vector; 0-based)" is the index at which the entry is located in the sorted vector using 0-based indexing. 

**5. Show all entries in the database**

Shows all entries in the database - sorted alphabetically.

**6. Show help commands**

Shows help commands such as `_back`.

# Edge Cases

For now, this CRUD app does not handle all edge cases when adding, updating, deleting, and searching entries.

1) Words that contain spaces will not work, i.e., `Flower Pot`.

2) The flat-file database only contains entries as a plain list and not like a traditional database with columns. So doing very specific adding, updating, deleting, searching, and showing from/to a specific column are not handled.
