#ifndef QWSFRAME_H
#define QWSFRAME_H

#include "QWsSocket.h"

#include <QByteArray>

class QWsFrame
{

public:

  QWsFrame();
  void clear();
  QByteArray data() const; // TODO make const
  bool valid() const;
  QByteArray unmask() const;
  bool controlFrame() const;

  QWsSocket::EReadingState readingState;

  bool final;
  quint8 rsv;
  bool hasMask;
  QWsSocket::EOpcode opcode;
  qint64 payloadLength;
  char maskingKey[4]; // TODO convert to quint8
  QByteArray payload;
};

#endif
