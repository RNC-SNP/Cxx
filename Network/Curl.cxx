#include <iostream>
#include <string>
#include <map>
#include <curl/curl.h>
#include <stdio.h>

static size_t http_write_func(void *new_data, size_t size, size_t nmemb, void *data) {
	size_t new_data_size = size * nmemb;
	((std::string*)data)->append((char*)new_data, new_data_size);
	return new_data_size;
}

static std::string http(const std::string url, const std::map<std::string, std::string> headers, const std::map<std::string, std::string> params, bool is_post, long timeout) {
	std::string output;
	CURL *curl = curl_easy_init();
	if (curl) {
		struct curl_slist *m_headers = NULL;
		for (auto h_it = headers.begin(); h_it != headers.end(); ++h_it) {
			std::string headers_str;
			headers_str.append(h_it->first).append(": ").append(h_it->second);
			curl_slist_append(m_headers, headers_str.c_str());
		}

		std::string params_str;
		for (auto p_it = params.begin(); p_it != params.end(); ++p_it) {
			if (params_str.length() > 0) {
				params_str.append("&");
			}
			params_str.append(p_it->first).append("=").append(p_it->second);
		}

		std::string url_str;
		url_str.append(url);
		if (!is_post) {
			url_str.append("?").append(params_str);
		}

		curl_easy_setopt(curl, CURLOPT_URL, url_str.c_str());
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
		if (m_headers != NULL) {
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, m_headers);
		}
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, http_write_func);
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

static size_t download_write_func(void *new_data, size_t size, size_t nmemb, void *data) {
	return fwrite(new_data, size, nmemb, (FILE *)data);
}

/*
static int download_progress_func(void *ptr, double total_to_download, double current_downloaded, double total_to_upload, double current_uploaded) {
	if (total_to_download > 0.0) {
		double progress = current_downloaded * 100 / total_to_download;
		std::cout << progress << "%" << std::endl;
	}
	return 0;
}
*/

static void download(const std::string src_url, const std::string dst_file, long timeout) {
	FILE *file = fopen(dst_file.c_str(), "wb");
	if (file) {
		CURL *curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, src_url.c_str());
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download_write_func);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
			/*
			curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
			curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, download_progress_func);
			*/
			CURLcode code = curl_easy_perform(curl);
			if (code != CURLE_OK) {
				std::cout << curl_easy_strerror(code) << std::endl;
			}
			curl_easy_cleanup(curl);
		}
	} else {
		std::cout << "Open file failed." << std::endl;
	}
}

int main(int argc, char** argv) {
	const long timeout = 15L;

	const std::string url1 = "https://api.douban.com/v2/user";
	std::map<std::string, std::string> headers1;
	std::map<std::string, std::string> params1;
	params1.insert(std::pair<std::string, std::string>("q", "rinc"));
	params1.insert(std::pair<std::string, std::string>("count", std::to_string(10)));
	std::string res1 = http(url1, headers1, params1, false, timeout);
	std::cout << res1 << std::endl;

	const std::string url2 = "https://api.douban.com/v2/book/25923597/collection";
	std::map<std::string, std::string> headers2;
	std::map<std::string, std::string> params2;
	params2.insert(std::pair<std::string, std::string>("status", "wish"));
	params2.insert(std::pair<std::string, std::string>("rating", std::to_string(5)));
	std::string res2 = http(url2, headers2, params2, true, timeout);
	std::cout << res2 << std::endl;

	const std::string url3 = "https://raw.githubusercontent.com/RincLiu/Cxx-Snippets/master/Network/Curl.cxx";
	const std::string file = "xxx.txt";
	download(url3, file, timeout);

	return 0;
}
