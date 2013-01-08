void Driver::Run()
{
  IPCMessageType msg;
  DeviceInterruptMessage interruptMessage(&msg);
  DeviceIOMessage ioMessage(&msg);
  DeviceIOControlMessage ioctlMessage(&msg);
  DeviceIOVectorMessage ioVectorMessage(&msg);
  DeviceEntranceMessage entranceMessage(&msg);
  DeviceCancelMessage cancelMessage(&msg);
  DeviceTimeoutMessage timeoutMessage(&msg);

  int ret = _ddm->RegisterDriver(_name, _busOwner);
  if (DDM_RETURN_OK != ret) {
    panic(_name, "error registering driver with DDM", ret);
  }

  Initialize();

  while (1) {
    ret = receive(ANY, &msg);
    if (ret) {
      panic(_name, "error getting message", ret);
    }

    switch(msg.m_type) {
    case DEVICE_INTERRUPT:
      InterruptHandler(interruptMessage);
      continue;
    case DEVICE_READ:
      ReadHandler(ioMessage);
      break;
    case DEVICE_WRITE:
      WriteHandler(ioMessage);
      break;
    case DEVICE_IO_CONTROL:
      IOControlHandler(ioctlMessage);
      break;
    case DEVICE_SCATTER:
      ScatterHandler(ioVectorMessage);
      break;
    case DEVICE_GATHER:
      GatherHandler(ioVectorMessage);
      break;
    case DEVICE_OPEN:
      OpenHandler(entranceMessage);
      break;
    case DEVICE_CLOSE:
      CloseHandler(entranceMessage);
      break;
    case DEVICE_CANCEL:
      CancelHandler(cancelMessage);
      break;
    case SYN_ALARM:
      TimeoutHandler(timeoutMessage);
      break;
    case PROC_EVENT:
    case SYS_SIG:
      QuitHandler();
      return;
    }

    ret = send(msg.m_source, &msg);
    if (ret) {
      panic(_name, "error sending message", ret);
    }
  }
}

void Driver::InterruptHandler(DeviceInterruptMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::ReadHandler(DeviceIOMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::WriteHandler(DeviceIOMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::IOControlHandler(DeviceIOControlMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::ScatterHandler(DeviceIOVectorMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::GatherHandler(DeviceIOVectorMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::OpenHandler(DeviceEntranceMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::CloseHandler(DeviceEntranceMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::CancelHandler(DeviceCancelMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::TimeoutHandler(DeviceTimeoutMessage &msg)
{
  msg.CallType() = DEVICE_RETURN_ERROR_NOT_IMPLEMENTED;
}

void Driver::QuitHandler()
{
  int ret = _ddm->UnregisterDriver(_name);
  if (DDM_RETURN_OK != ret) {
    panic(_name, "error unregistering driver with DDM", ret);
  }
}
