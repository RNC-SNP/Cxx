#include <iostream>
#include <string>
#include <map>
#include <curl/curl.h>

static size_t write_func(void *new_data, size_t size, size_t nmemb, void *data) {
  size_t new_data_size = size * nmemb;
  ((std::string*)data)->append((char*)new_data, new_data_size);
  return new_data_size;
}

static std::string http(std::string url, const std::map<std::string, std::string> params, bool is_post, long timeout) {
  std::string output;
  CURL *curl = curl_easy_init();
  if (curl) {
    std::string params_str;
    for (auto it = params.begin(); it != params.end(); ++it) {
      if (params_str.length() > 0) {
        params_str.append("&");
      }
      params_str.append(it->first).append("=").append(it->second);
    }

    if (!is_post) {
      url.append("?").append(params_str);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

    if (is_post) {
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params_str.c_str());
    }

    CURLcode code = curl_easy_perform(curl);
    if (code != CURLE_OK) {
      std::cout << curl_easy_strerror(code) << std::endl;
    }

    curl_easy_cleanup(curl);
  }
  return output;
}

int main(int argc, char** argv) {
  const long timeout = 10L;

  std::map<std::string, std::string> params1;
  params1.insert(std::pair<std::string, std::string>("q", "rinc"));
  params1.insert(std::pair<std::string, std::string>("count", std::to_string(10)));
  std::string res1 = http("https://api.douban.com/v2/user", params1, false, timeout);
  std::cout << res1 << std::endl;

  std::map<std::string, std::string> params2;
  params2.insert(std::pair<std::string, std::string>("status", "wish"));
  params2.insert(std::pair<std::string, std::string>("rating", std::to_string(5)));
  std::string res2 = http("https://api.douban.com/v2/book/25923597/collection", params2, true, timeout);
  std::cout << res2 << std::endl;

  return 0;
}
