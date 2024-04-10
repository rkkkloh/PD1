#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IP_LENGTH 32

struct prefix {
    unsigned ip;
    unsigned char len;
    struct prefix *next;
};

struct prefix *input(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct prefix *head = NULL;
    struct prefix *current = NULL;
    char line[MAX_IP_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "/");
        if (token != NULL) {
            unsigned ip = 0;
            unsigned int ip_parts[4];
            if (sscanf(token, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]) == 4) {
                ip = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
                //printf("%d%d%d%d\n",ip_parts[0],ip_parts[1],ip_parts[2],ip_parts[3]);
                //printf("%u\n",ip);
                token = strtok(NULL, "/");
                if (token != NULL) {
                    unsigned char len = atoi(token);

                    // Create a new prefix node
                    struct prefix *new_prefix = (struct prefix *)malloc(sizeof(struct prefix));
                    if (new_prefix != NULL) {
                        new_prefix->ip = ip;
                        new_prefix->len = len;
                        new_prefix->next = NULL;

                        if (head == NULL) {
                            head = new_prefix;
                            current = head;
                        } else {
                            current->next = new_prefix;
                            current = current->next;
                        }
                    } else {
                        printf("Memory allocation failed!\n");
                        fclose(file);
                        return NULL;
                    }
                }
            }
        }
    }
    fclose(file);
    return head;
}

void length_distribution(struct prefix *head) {
    int i, count;
    for (i = 0; i <= 32; ++i) {
        count = 0;
        struct prefix *temp = head;
        while (temp != NULL) {
            if (temp->len == i)
                count++;
            temp = temp->next;
        }
        //printf("The number of prefixes with prefix length %d = %d\n", i, count);
    }

}

struct prefix *segment(struct prefix *head, int d) {
    int num_groups = 1 << d;
    int i, count;
    for (i = 0; i < num_groups; ++i) {
        count = 0;
        struct prefix *temp = head;
        while (temp != NULL) {
            if ((temp->ip>>24 == i) && temp->len >= d)
                count++;
            temp = temp->next;
        }
        printf("The number of prefixes in group %d = %d\n", i, count);
    }
}

struct prefix *prefix_insert(struct prefix *head, const char *filename) {

    FILE *file = fopen(filename, "r");
    char line[MAX_IP_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "/");
        if (token != NULL) {
            unsigned ip = 0;
            unsigned int ip_parts[4];
            if (sscanf(token, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]) == 4) {
                ip = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
                //printf("%d%d%d%d\n",ip_parts[0],ip_parts[1],ip_parts[2],ip_parts[3]);

                token = strtok(NULL, "/");
                if (token != NULL) {
                    unsigned len = atoi(token);

                    // Create a new prefix node
                    struct prefix *newNode = (struct prefix *)malloc(sizeof(struct prefix));
                    if (newNode != NULL) {
                        newNode->ip = ip;
                        newNode->len = len;
                        newNode->next = NULL;

                        struct prefix *temp = head;
                        if (temp != NULL) {
                                while (temp->next != NULL) {
                                        temp = temp->next;
                                }
                                temp->next = newNode;
                        }
                    } else {
                        printf("Memory allocation failed!\n");
                        fclose(file);
                        return NULL;
                    }
                }
            }
        }
    }
    fclose(file);
    return head;
}

struct prefix *prefix_delete(struct prefix *head, const char *filename) {
    uint32_t ip = 0;
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char line[MAX_IP_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "/");
        if (token != NULL) {
            unsigned int ip_parts[4];
            if (sscanf(token, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]) == 4) {
                ip = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
            }
            //printf("%d%d%d%d\n",ip_parts[0],ip_parts[1],ip_parts[2],ip_parts[3]);
        }
        struct prefix *cur , *prev = NULL;
        cur = head;

        while(cur!=NULL)
        {
            if(cur->ip==ip)
                break;
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        if(cur != NULL)
        {
            if(prev != NULL)
            {
                prev->next = cur->next;
            }
            else
                head =  cur->next;
        }
        free(cur);
    }
    fclose(file);
    return head;
}

void search(struct prefix *head, const char *filename) {
    unsigned ip = 0;
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return ;
    }
    char line[MAX_IP_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "/");
        if (token != NULL) {

            unsigned int ip_parts[4];
            if (sscanf(token, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]) == 4) {
                ip = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
            }
        }
        struct prefix *cur;
        cur = head;

        while(cur!=NULL)
        {
            if(cur->ip==ip)
                break;
            else
            {
                cur = cur->next;
            }
        }
        if(cur != NULL){
            printf("yes\n");

        }
        else{
            printf("no\n");
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {

	const char *routing_table = argv[1];
        const char *inserted_prefixes = argv[2];
	const char *delete_prefixes = argv[3];
	const char *trace_file = argv[4];
	int d = atoi(argv[5]);

    struct prefix *prefixes = input(routing_table);
    if (prefixes == NULL) {
        return 1;
    }

    int total_prefixes = 0;
    struct prefix *temp = prefixes;
    while (temp != NULL) {
        total_prefixes++;
        temp = temp->next;
    }
    printf("The total number of prefixes in the input file is : %d.\n", total_prefixes);

    length_distribution(prefixes);

    struct prefix *sghead = segment(prefixes, d);
    //struct prefix *tmp = sghead;
    //while (tmp != NULL) {
    //    printf("%u\n",tmp->ip);
    //    tmp = tmp->next;
    //}

    //prefixes = prefix_insert(prefixes, inserted_prefixes);
    /*struct prefix *tmp = prefixes;
    while (tmp != NULL) {
        printf("%u\n",tmp->ip);
        tmp = tmp->next;
    }*/
    /*prefixes = prefix_delete(prefixes, delete_prefixes);
    struct prefix *tmp = prefixes;
    while (tmp != NULL) {
        printf("%u\n",tmp->ip);
        tmp = tmp->next;
    }*/
    //search(prefixes,trace_file);


  return 0;
}

