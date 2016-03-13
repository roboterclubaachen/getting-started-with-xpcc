#include <xpcc/architecture/platform.hpp>

int main()
{
	Board::initialize();
	Board::Leds::setOutput();

	while (1)
	{
		Board::Leds::toggle();
		xpcc::delayMilliseconds(Board::Button::read() ? 250 : 500);
#ifdef XPCC_BOARD_HAS_LOGGER
		static uint32_t counter(0);
		XPCC_LOG_INFO << "Loop counter: " << (counter++) << xpcc::endl;
#endif
	}
	return 0;
}
