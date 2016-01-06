#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t write_func(void *new_data, size_t size, size_t nmemb, void *data) {
  size_t new_data_size = size * nmemb;
  ((std::string*)data)->append((char*)new_data, new_data_size);
  return new_data_size;
}

static std::string http(const std::string url, const std::params, bool is_post) {
  CURL *curl;
  std::string output;
  curl = curl_easy_init();
  if (curl) {
    if (is_post) {
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);
    } else {
      url += "?";
      url += params;
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
    CURLcode code = curl_easy_perform(curl);
    if (code != CURLE_OK) {
      std::cout << curl_easy_strerror(code) << std::endl;
    }
    curl_easy_cleanup(curl);
  }
  return output;
}

int main(int argc, char** argv) {
  std::string get = http("https://api.douban.com/v2/user", "q=rinc&count=10", false);
  std::cout << get << std::endl;
  std::string post = http("https://api.douban.com/v2/book/25923597/collection", "status=wish&rating=5", true);
  std::cout << post << std::endl;
  return 0;
}
