// Warning: Ugly Managed C++ Alert
// Strongly based on http://msdn.microsoft.com/en-us/library/system.io.ports.serialport.aspx?cs-save-lang=1&cs-lang=cpp#code-snippet-2
// The C# here really just opens the COM port and listens for messages from it,
// sending the message to the C(++) to handle it and send inputs.
#using <System.dll>

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;

public ref class HudlRemotes
{
private:
	static bool _continue;
	static SerialPort^ _serialPort;

public:
	static void Main()
	{
		int connectionStatus = 0; // Port we are trying to connect to
		String^ port3 = "COM3";
		String^ port2 = "COM2";
		String^ port0 = "COM1";
		String^ port0 = "COM0";
		Thread^ readThread = gcnew Thread(gcnew ThreadStart(HudlRemotes::Read));

		// Set up a serial port
		_serialPort = gcnew SerialPort();

		// We're assuming this is the only serial device present for now...
		_serialPort->PortName = SerialPort::GetPortNames()[0];
		_serialPort->BaudRate = 56000;
		_serialPort->Parity = Parity::None;
		_serialPort->DataBits = 8;
		_serialPort->StopBits = StopBits::One
		_serialPort->Handshake = 




	}
	
	static Handshake SetPortHandshake(Handshake defaultPortHandshake)
	{
		String^ handshake;

		Console::WriteLine("Available Handshake options:");
		for each (String^ s in Enum::GetNames(Handshake::typeid))
		{
			Console::WriteLine("   {0}", s);
		}

		Console::Write("Handshake({0}):", defaultPortHandshake.ToString());
		handshake = Console::ReadLine();

		if (handshake == "")
		{
			handshake = defaultPortHandshake.ToString();
		}

		return (Handshake)Enum::Parse(Handshake::typeid, handshake);
	}