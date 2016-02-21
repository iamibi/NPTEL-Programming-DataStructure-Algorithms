char * getTopper(struct Student s[], int nStudents, int subjectIndex, int nSubjects)
{
    /*
    Return name of topper of a subject. 
    Arguments :
	    array of Student records.
	    number of Students (nStudents).
	    index of subject for which function should find toper (subjectIndex).
	    number of Subjects (nSubjects)
    */
    int i, loc = 0;
    float max = 0.0f;

    max = s[0].marks[subjectIndex];
    for (i = 1; i < nStudents; i++)
    {
        if (s[i].marks[subjectIndex] > max)
        {
            max = s[i].marks[subjectIndex];
            loc = i;
        }
    }

    return (s[loc].name);
}

float getAvg(struct Student  s, int nSubjects)
{
    /* 
    return avg mark of a student. 
    Arguments :
	    a Student record s.
	    number of Subjects (nSubjects)
    */
    int i;
    float avg = 0.0;

    for (i = 0; i < nSubjects; i++)
        avg = avg + s.marks[i];

    return (avg / nSubjects);
}

void setValues(struct Student* s, const char * name, float marks[], int nSubjects)
{
    /* 
    set values in structure Student 
    Arguments :
	    a pointer to a Student record (s).
	    name of Student (name).
	    mark of K subjects (marks).
	    number of Subjects (nSubjects) 
    */
    
    strcpy(s -> name, name);
    int i;
    
    for (i = 0; i < nSubjects; i++)
        s -> marks[i] = marks[i];
}
