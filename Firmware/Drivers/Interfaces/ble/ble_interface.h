/*
 * ble_interface.h
 *
 *  Created on: 02.10.2018
 *      Author: tobi
 */

#include <stdbool.h>

/*
 * 1 -> Init
 * 2 -> Either Connect or Allow Connection
 *
 */

typedef struct {
	uint8_t mac;
	uint8_t ip;
} ble_interface_dev_id;

void ble_interface_init();
void ble_interface_send(uint8_t * tx_buffer, uint8_t tx_buffer_length);
uint16_t ble_interface_get_buffer_length();
uint16_t ble_interface_get_buffer(uint8_t *rx_buffer, uint8_t rx_buffer_length);
void ble_interface_deinit();

void ble_interface_connect(const ble_interface_dev_id * dev_id);
void ble_interface_disconnect(const ble_interface_dev_id * dev_id);
void ble_interface_set_name(const uint8_t * ble_name, const uint8_t ble_name_len);
void ble_interface_advertize(const bool ble_advertize);