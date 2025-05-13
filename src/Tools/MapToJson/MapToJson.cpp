#include "MapToJson.h"

std::string unescapeJsonString(const std::string& input) {
    std::ostringstream ss;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '\\' && i + 1 < input.size()) {
            switch (input[i + 1]) {
            case '\\': ss << '\\'; break;
            case '"': ss << '"'; break;
            case '/': ss << '/'; break;
            case 'b': ss << '\b'; break;
            case 'f': ss << '\f'; break;
            case 'n': ss << '\n'; break;
            case 'r': ss << '\r'; break;
            case 't': ss << '\t'; break;
            default: ss << input[i + 1]; break; // 不处理其他转义序列
            }
            ++i; // 跳过下一个字符
        }
        else {
            ss << input[i];
        }
    }
    return ss.str();
}

std::map<std::string, std::string> jsonToMap(const std::string& jsonStr) {
    std::map<std::string, std::string> result;

    size_t i = 0;
    auto skipWhitespace = [&]() {
        while (i < jsonStr.size() && isspace(jsonStr[i])) i++;
        };

    auto expect = [&](char c) {
        skipWhitespace();
        if (i >= jsonStr.size() || jsonStr[i] != c) {
            throw std::runtime_error("Unexpected JSON format");
        }
        i++;
        };

    try {
        expect('{');
        skipWhitespace();

        while (i < jsonStr.size() && jsonStr[i] != '}') {
            // 读取key
            expect('"');
            size_t keyStart = i;
            while (i < jsonStr.size() && jsonStr[i] != '"') {
                if (jsonStr[i] == '\\') i++; // 跳过转义字符
                i++;
            }
            if (i >= jsonStr.size()) throw std::runtime_error("Unterminated string");
            std::string key = jsonStr.substr(keyStart, i - keyStart);
            i++; // 跳过结尾的"

            key = unescapeJsonString(key);

            // 读取分隔符
            expect(':');

            // 读取value
            expect('"');
            size_t valueStart = i;
            while (i < jsonStr.size() && jsonStr[i] != '"') {
                if (jsonStr[i] == '\\') i++; // 跳过转义字符
                i++;
            }
            if (i >= jsonStr.size()) throw std::runtime_error("Unterminated string");
            std::string value = jsonStr.substr(valueStart, i - valueStart);
            i++; // 跳过结尾的"

            value = unescapeJsonString(value);

            result[key] = value;

            skipWhitespace();
            if (i < jsonStr.size() && jsonStr[i] == ',') {
                i++;
                skipWhitespace();
            }
        }

        expect('}');
    }
    catch (const std::exception& e) {
        // 解析失败返回空map或抛出异常
        throw; // 或者 return std::map<std::string, std::string>();
    }

    return result;
}

std::string escapeJsonString(const std::string& input) {
    std::ostringstream ss;
    for (auto iter = input.begin(); iter != input.end(); iter++) {
        switch (*iter) {
        case '\\': ss << "\\\\"; break;
        case '"': ss << "\\\""; break;
        case '/': ss << "\\/"; break;
        case '\b': ss << "\\b"; break;
        case '\f': ss << "\\f"; break;
        case '\n': ss << "\\n"; break;
        case '\r': ss << "\\r"; break;
        case '\t': ss << "\\t"; break;
        default: ss << *iter; break;
        }
    }
    return ss.str();
}

std::string mapToJson(const std::map<std::string, std::string>& data) {
    std::ostringstream json;
    json << "{";

    bool first = true;
    for (const auto& pair : data) {
        if (!first) {
            json << ",";
        }
        first = false;

        json << "\"" << escapeJsonString(pair.first) << "\":"
            << "\"" << escapeJsonString(pair.second) << "\"";
    }

    json << "}";
    return json.str();
}