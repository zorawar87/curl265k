#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define VERSION "1.0"

/*
 * discards the data, returns the number of bytes read
 */
static size_t WriteCallback (void *buffer, size_t size, size_t nmemb,
                             void *data) {
  (void)buffer;  /* unused */
  (void)data; /* unused */
  fprintf(stdout, "%d\n", (size_t) (size*nmemb));
  return (size_t) (size * nmemb);
}

int main (int argc, char *argv[]) {
  CURL *curl_handle;
  CURLcode res;
  const char *url = "https://google.com";
  char *appname = argv[0];

  if (argc > 1) {
    /* parse input parameters */
    for (argc--, argv++; *argv; argc--, argv++) {
      if (strncasecmp (*argv, "-", 1) == 0) {
        if (strncasecmp (*argv, "-H", 2) == 0) {
          fprintf (stderr,
                   "\rUsage: %s [url]\n",
                   appname);
          exit (1);
        } else if (strncasecmp (*argv, "-V", 2) == 0) {
          fprintf (stderr, "\r%s %s - %s\n",
                   appname, VERSION, curl_version());
          exit (1);
        } else {
          fprintf (stderr, "\r%s: invalid or unknown option %s\n",
                   appname, *argv);
          exit (1);
        }
      } else
        url = *argv;
    }
  }

  // initialise libcurl
  curl_global_init (CURL_GLOBAL_DEFAULT);
  /* one handle per easy session
     use one handle for every thread you use for transferring
     MUST NEVER share the same handle in multiple threads. */
  curl_handle = curl_easy_init();
  // specify the URL to get
  curl_easy_setopt (curl_handle, CURLOPT_URL, url);
  // send all data to this function
  curl_easy_setopt (curl_handle, CURLOPT_WRITEFUNCTION, WriteCallback);
  /* some servers don't like requests that are made without a user-agent
     field, so we provide one */
  curl_easy_setopt (curl_handle, CURLOPT_USERAGENT, "libcurl265K/" VERSION);
  res = curl_easy_perform(curl_handle);
  if (res == CURLE_OK) fprintf(stderr, "OK\n");
  else fprintf (stderr, "NOT OK\n");
  curl_easy_cleanup(curl_handle);
}
