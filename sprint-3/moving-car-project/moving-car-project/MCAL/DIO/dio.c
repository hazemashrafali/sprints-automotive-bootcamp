#include "dio.h"

/**
 * @brief Initializes the direction of the specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port in invalid.
 * @return DIO_SUCCESS The pin initialization is a success.
 */
EN_DIO_ERROR_STATE DIO_Init(DIO_Init_t *p_config_struct) {
    uint8 port_num = p_config_struct -> port;
    switch (port_num) {
        case PORT_A:
            if (p_config_struct -> direction == DIO_INPUT) {
                // Clear bit.
                CLEAR_BIT(DDRA,p_config_struct -> pin);
            } else if (p_config_struct -> direction == DIO_OUTPUT) {
                // Set bit.
                SET_BIT(DDRA,p_config_struct -> pin);
            }
            break;
        case PORT_B:
            if (p_config_struct -> direction == DIO_INPUT) {
                // Clear bit.
                CLEAR_BIT(DDRB,p_config_struct -> pin);
            } else if (p_config_struct -> direction == DIO_OUTPUT) {
                // Set bit.
                SET_BIT(DDRB,p_config_struct -> pin);
            }
            break;
        case PORT_C:
            if (p_config_struct -> direction == DIO_INPUT) {
                // Clear bit.
                CLEAR_BIT(DDRC,p_config_struct -> pin);
            } else if (p_config_struct -> direction == DIO_OUTPUT) {
                // Set bit.
                SET_BIT(DDRC,p_config_struct -> pin);
            }
            break;
        case PORT_D:
            if (p_config_struct -> direction == DIO_INPUT) {
                // Clear bit.
                CLEAR_BIT(DDRD,p_config_struct -> pin);
            } else if (p_config_struct -> direction == DIO_OUTPUT) {
                // Set bit.
                SET_BIT(DDRD,p_config_struct -> pin);
            }
            break;
        default:
            return DIO_PORT_INVALID;
    }
    return DIO_SUCCESS;
}

/**
 * @brief Reads the state of a specific pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Reading from a pin that is configured as output.
 * @return DIO_SUCCESS The read operation is a success.
 */
EN_DIO_ERROR_STATE DIO_ReadPin(DIO_Init_t *p_config_struct) {
    uint8 port_num = p_config_struct -> port;
    if (p_config_struct -> direction == DIO_INPUT) {
        switch (port_num) {
            case PORT_A:
                if (BIT_IS_SET(PINA,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_HIGH;
                } else if (BIT_IS_CLEAR(PINA,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_LOW;
                }
                break;
            case PORT_B:
                if (BIT_IS_SET(PINB,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_HIGH;
                } else if (BIT_IS_CLEAR(PINB,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_LOW;
                }
                break;
            case PORT_C:
                if (BIT_IS_SET(PINC,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_HIGH;
                } else if (BIT_IS_CLEAR(PINC,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_LOW;
                }
                break;
            case PORT_D:
                if (BIT_IS_SET(PIND,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_HIGH;
                } else if (BIT_IS_CLEAR(PIND,p_config_struct -> pin)) {
                    p_config_struct -> pin_value = DIO_LOW;
                }
                break;
            default:
                return DIO_PORT_INVALID;
        }
    } else {
        return DIO_DIRECTION_INVALID;
    }
    return DIO_SUCCESS;
}

/**
 * @brief Write a specific level to a specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Writing to a pin that is configured as input.
 * @return DIO_SUCCESS The write operation is a success.
 */
EN_DIO_ERROR_STATE DIO_WritePin(DIO_Init_t *p_config_struct) {
    uint8 port_num = p_config_struct -> port;
    if (p_config_struct -> direction == DIO_OUTPUT) {
        switch (port_num) {
            case PORT_A:
                if (p_config_struct -> port_value == DIO_HIGH) {
                    SET_BIT(PORTA,p_config_struct -> pin);
                } else if (p_config_struct -> port_value == DIO_LOW) {
                    CLEAR_BIT(PORTA,p_config_struct -> pin);
                }
                break;
            case PORT_B:
                if (p_config_struct -> port_value == DIO_HIGH) {
                    SET_BIT(PORTB,p_config_struct -> pin);
                } else if (p_config_struct -> port_value == DIO_LOW) {
                    CLEAR_BIT(PORTB,p_config_struct -> pin);
                }
                break;
            case PORT_C:
                if (p_config_struct -> port_value == DIO_HIGH) {
                    SET_BIT(PORTC,p_config_struct -> pin);
                } else if (p_config_struct -> port_value == DIO_LOW) {
                    CLEAR_BIT(PORTC,p_config_struct -> pin);
                }
                break;
            case PORT_D:
                if (p_config_struct -> port_value == DIO_HIGH) {
                    SET_BIT(PORTD,p_config_struct -> pin);
                } else if (p_config_struct -> port_value == DIO_LOW) {
                    CLEAR_BIT(PORTD,p_config_struct -> pin);
                }
                break;
            default:
                return DIO_PORT_INVALID;
        }
    } else {
        return DIO_DIRECTION_INVALID;
    }
    return DIO_SUCCESS;
}

/**
 * @brief Toggles the current level of a pin.
 * @param[in] p_config_struct Address of the configuration structure.
 *  @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Toggle a pin that is configured as input.
 * @return DIO_SUCCESS The toggle operation is a success.
 */
EN_DIO_ERROR_STATE DIO_TogglePin(DIO_Init_t *p_config_struct) {
    uint8 port_num = p_config_struct ->port;
    if (p_config_struct -> direction == DIO_OUTPUT) {
        switch (port_num) {
            case PORT_A:
                TOGGLE_BIT(PORTA,p_config_struct -> pin);
                break;
            case PORT_B:
                TOGGLE_BIT(PORTB,p_config_struct -> pin);
                break;
            case PORT_C:
                TOGGLE_BIT(PORTC,p_config_struct -> pin);
                break;
            case PORT_D:
                TOGGLE_BIT(PORTD,p_config_struct -> pin);
                break;
            default:
                return DIO_PORT_INVALID;
        }
    } else {
        return DIO_DIRECTION_INVALID;
    }
    return DIO_SUCCESS;
}