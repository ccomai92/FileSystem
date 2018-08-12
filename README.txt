CSS430: Operating System 
Final Project: File System 
Group: Kris Kwon (Gihwan KWon), Yuun Lim 
-----------------------------------------
Assumptions:
- A disk contains 1000 of 512K blocks (0 - 999)
    512K =  524288bytes
- Permissions and file type should be -rwxr--r--
- Use only direct blocks in INode
- uid = CSS430, gid = CSS430 

Commands:
- Format (initializes the File structure)
    syntax = FM
- Create new file 
    syntax = NF fileName numBlocks 
- Add to file 
    syntax = MF filename numblocks 
- Delete file 
    syntax = DF filename 
- Delete blocks 
    syntax = DB filename numblocks 




Output:
>> FM
>> NF Yuun.txt 5
>> NF Kris.txt 4
>> NF john.txt 3
>> ls
1 -rwxr--r-- CSS430 CSS430 2097152 2018-08-12.00:32:36 Kris.txt
0 -rwxr--r-- CSS430 CSS430 2621440 2018-08-12.00:32:30 Yuun.txt
2 -rwxr--r-- CSS430 CSS430 1572864 2018-08-12.00:32:39 john.txt
>> MF john.txt 3
>> ls
1 -rwxr--r-- CSS430 CSS430 2097152 2018-08-12.00:32:36 Kris.txt
0 -rwxr--r-- CSS430 CSS430 2621440 2018-08-12.00:32:30 Yuun.txt
2 -rwxr--r-- CSS430 CSS430 3145728 2018-08-12.00:33:00 john.txt
>> DB john.txt 3
>> ls
1 -rwxr--r-- CSS430 CSS430 2097152 2018-08-12.00:32:36 Kris.txt
0 -rwxr--r-- CSS430 CSS430 2621440 2018-08-12.00:32:30 Yuun.txt
2 -rwxr--r-- CSS430 CSS430 1572864 2018-08-12.00:33:15 john.txt
>> DF john.txt
>> ls
1 -rwxr--r-- CSS430 CSS430 2097152 2018-08-12.00:32:36 Kris.txt
0 -rwxr--r-- CSS430 CSS430 2621440 2018-08-12.00:32:30 Yuun.txt
>> DF john.txt
no such file exists
>> DB Kris.txt 10
Illegal argument exception the file is smaller
>> NF john.txt 20
File size is too big
>> quit