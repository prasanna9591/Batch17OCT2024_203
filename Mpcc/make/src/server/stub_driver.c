// stub_driver.c
#include <stdio.h>
#include <string.h>
#include "client_prg.c"
#include "client_send_recv.c"
#include "log_client_report.c"

int main() {
    char username[128], password[128];

    get_login_details(username, password);
    if (authenticate_existing_user(username, password)) {
        printf("User authenticated\n");
    } else {
        printf("Authentication failed\n");
    }

    return 0;
}

