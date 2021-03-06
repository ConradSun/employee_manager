//
//  log.h
//  EmployeeManager
//
//  Created by 孙康 on 2022/06/10.
//

#ifndef log_h
#define log_h

#ifdef UNIT_TEST
#define STATIC
#else
#define STATIC  static
#endif

/**
* @brief 日志打印等级
*/
typedef enum {
    LOG_OFF,        // 关闭日志
    LOG_FAULT,      // 严重错误
    LOG_ERROR,      // 错误信息
    LOG_INFO,       // 详细信息
    LOG_DEBUG,      // 调试信息
} log_level_t;

extern log_level_t g_log_level; // 当前日志等级

/**
* @brief 调试/测试日志接口
*/
#define LOG_C(level, format, ...) \
    if (g_log_level >= level) { \
        printf("%s %s:%d [-] " format "\n", \
            #level, __func__, __LINE__, ##__VA_ARGS__); \
    } \

/**
* @brief 直接打印日志接口
*/
#define LOG_O(format, ...) \
    printf(format "\n", ##__VA_ARGS__); \

#endif /* log_h */
