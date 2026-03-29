#include "dynamic_hashmap.h"

HashMap *hashmap_create() {
    HashMap *map = calloc(1, sizeof(HashMap));
    
    if (map == NULL) {
        printf("calloc failed in hashmap_create.\n");
        return;
    }
    //map->table = calloc(HASHMAP_INIT_CAPACITY, sizeof(KeyValueNode)); // error
    map->table = calloc(HASHMAP_INIT_CAPACITY, sizeof(KeyValueNode *));

    map->length = HASHMAP_INIT_CAPACITY;
    map->seed = time(NULL);

    return map;
}

/*
* key: 键，使用指针给我。 如果是字符串，直接给就行； 如果是int, 需要对它取地址
* len: 多少空间。 如果是字符串。 strlen； 如果是其他类型， 用sizeof()
* 在字符串中，它俩有什么区别
* seed: 种子。 想用它影响最终得到的哈希值。
*/
static uint32_t hash(const void *key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char *data = (const unsigned char *)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t *)data;
        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

ValueType hashmap_put(HashMap *map, KeyType key, ValueType value) {
    // 1.将给定的key值计算，转整数。 
    uint32_t hash_num = hash(key, strlen(key), map->seed);

    // 2.将得到的整数取余。 得到下标。 
    int index = hash_num % map->length;

    // 3.去这个下标看是否有数据。 如果有数据，遍历，找是否有重复的key。
    // 如果没有数据，直接插入。 
    KeyValueNode *cur_node = map->table[index];

    while (cur_node != NULL) {
        // 将数据判断清楚，是否有这个数据。 
        if (strcmp(key, cur_node->key) == 0) {
            // 如果这两个字符串内容相同。 这时候，key重复。 
            ValueType old_value = cur_node->value;
            cur_node->value = value;
            return old_value;
        }
        cur_node = cur_node->next;
    }

    // 走到这，有两种情况； 
    // 要么这个位置没有数据； 要么这个位置有数据，但是这个key没重复

    KeyValueNode *new_node = calloc(1, sizeof(KeyValueNode));
    new_node->key = key;
    new_node->value = value;

    new_node->next = map->table[index];
    map->table[index] = new_node;
    map->size++;

    // 如果 size / length > 3/4 说明超过了 加载因子阈值。 
    // if（）{grow}
    if ((1.0 * map->size / map->length) > LOAD_FACTOR_THRESHOLD) {
        // 说明超过了阈值。 这时候扩容。 
        // 1)能不能用realloc ？ 不行。 
        // 10101010111 % 10===> 1
        // 10101010111 % 20===> 11

        // 2) 需要使用calloc 申请得到一块大空间。 
        // 然后将之前数组上挂着的数据，依次应用添加流程，找到合适的位置，挂上去
        // 最后再将就旧数组释放掉。 


    }


    return NULL;
}

ValueType hashmap_get(HashMap *map, KeyType key) {
    // 1.转换int。 
    uint32_t hash_num = hash(key, strlen(key), map->seed);

    // 2.取余。 得到指定下标
    int index = hash_num % map->length;

    // 3.判断该位置是否有这个key
    KeyValueNode *cur_node = map->table[index];

    while (cur_node != NULL) {
        if (strcmp(cur_node->key, key) == 0) {
            return cur_node->value;
        }
        cur_node = cur_node->next;
    }

    return NULL;
}

ValueType hashmap_remove(HashMap *map, KeyType key) {
    // 1.转int
    uint32_t hash_num = hash(key, strlen(key), map->seed);

    // 2.取余
    int index = hash_num % map->length;

    // 3.得到指定位置的数据，挨个判断。 如果相同。 我们需要它的前驱，才能删除它
    KeyValueNode *cur_node = map->table[index];

    if (cur_node == NULL) {
        // 说明。 没有数据。 
        return NULL;
    }

    if (strcmp(key, cur_node->key) == 0) {
        // 说明第一个结点就是我要删除的结点。 
        ValueType old_value = cur_node->value;

        map->table[index] = cur_node->next;
        free(cur_node);
        map->size--;
        return old_value;
    }

    // 说明第一个不是我要删除的结点。 
    KeyValueNode *pre_node = cur_node;
    cur_node = cur_node->next;
    while (cur_node != NULL)
    {
        if (strcmp(key, cur_node->key) == 0) {
            ValueType old_value = cur_node->value;

            pre_node->next = cur_node->next;
            free(cur_node);
            map->size--;
            return old_value;
        }
        pre_node = cur_node;
        cur_node = cur_node->next;
    }

    return NULL;
}