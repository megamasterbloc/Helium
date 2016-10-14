#ifndef ESCHER_TEXT_FIELD_H
#define ESCHER_TEXT_FIELD_H

#include <escher/view.h>
#include <escher/responder.h>
#include <string.h>

class TextField : public View, public Responder {
public:
  TextField(Responder * parentResponder, char * textBuffer, size_t textBufferSize);
  // View
  void drawRect(KDContext * ctx, KDRect rect) const override;
  // Responder
  bool handleEvent(Ion::Events::Event event) override;

  const char * textBuffer() const;
  void setTextBuffer(const char * text);
protected:
#if ESCHER_VIEW_LOGGING
  const char * className() const override;
#endif
private:
  char * m_textBuffer;
  size_t m_textBufferSize;
  size_t m_currentTextLength;
};

#endif
