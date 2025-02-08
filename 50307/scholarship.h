struct Class {
    int credit, type, score;
    // type = 0 : compulsory, 1 : elective, 2 : others
};
struct Student {
    char id[4];
    int k;
    struct Class classes[10];

    // calculate values below by yourself
    double gpa_avg, comp_avg, elec_avg;
    int major, total;
};

void scholarship(int n, struct Student students[]);
