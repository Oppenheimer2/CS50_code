#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool cycle(int winner,int loser);
bool check_loop(bool arr[],int i);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        //test
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i",ranks[j]);
        }

        record_preferences(ranks);

        printf("\n");
    }

    //test
    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%i",preferences[j][i]);
        }
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    //test
    printf("\n");
    for (int i = 0; i < 3; i++)
     {
        for (int j = 0; j < 3; j++)
        {
            printf("%i",locked[i][j]);
        }
        printf("\n");
     }
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    bool t = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            t = true;

        }

    }
    return t;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 1; j < candidate_count - i ; j++)
        {
                preferences[ranks[i]][ranks[j + i]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int weight[MAX * (MAX - 1) / 2];
    for (int i = 0; i < candidate_count; i++)
    {
        weight[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - 2; j++)
        {
            if(weight[j] < weight[j+1])
            {
                int a = weight[j];
                int b = weight[j+1];
                weight[j] = b;
                weight[j+1] = a;
                pair c = pairs[j];
                pair d = pairs[j+1];
                pairs[j] = d;
                pairs[j+1] = c;
            }
        }
    }
    //test
    for (int i = 0; i < MAX; i++)
    {
        printf("weight %i,",weight[i]);
    }
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
     for (int i = 0; i < MAX * (MAX - 1) / 2; i++)
     {
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].loser][pairs[i].winner] = false;
        bool t;
        if (cycle(pairs[i].winner,pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
     }

    return;
}

// Print the winner of the election
void print_winner(void)
{

    // TODO
    int i;
    for ( i = 0; i < candidate_count ; i++)
    {
        bool x = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                x = false;
            }
        }
        if(x)
        {
            break;
        }
    }
    printf("%s",candidates[i]);

    return;
}
bool check_loop(bool arr[], int i)
{
        bool visited[MAX];
        for (int j = 0; j < MAX; j++)
        {
            if (arr[j])
            {
                visited[j] = true;
            }
        }
        if (visited[i])
        {
            return true;
        }
        else
        {
            return false;
        }
}
bool cycle(int winner,int loser)
{
    if(locked[loser][winner] == true)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true && cycle(winner,i))
        {
            return true;
        }
    }
    return false;
}