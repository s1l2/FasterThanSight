#pragma once
#include "compiler/compiler_warnings_control.h"
#include "lang/enum.h"

DISABLE_COMPILER_WARNINGS
#include <QString>
RESTORE_COMPILER_WARNINGS

class TextFragment
{
public:
	// Ordered by priority!
	enum DelimiterEnum {
		NoDelimiter,
		Space,
		Dash,
		Bracket,
		Quote,
		Comma,
		Colon,
		Semicolon,
		Point,
		Ellipsis,
		ExclamationMark,
		QuestionMark,
		Newline
	};

	typedef Enum<DelimiterEnum> Delimiter;

	enum PivotCalculationMethod {
		pcmMagic,

		pcmMiddle,
		pcmQuarter,
		pcmSquareRoot,
		pcmCubicRoot,
		pcmLogarithm
	};

	inline TextFragment() {}
	TextFragment(const QString& word, const QString& punctuation, Delimiter delimiter = NoDelimiter);

	// Word + possible punctuation following it
	QString text() const;
	// Just the word
	QString word() const;
	// Just the punctuation
	QString punctuation() const;
	Delimiter delimiter() const;

	int pivotLetterIndex(PivotCalculationMethod method) const;
	bool isEndOfSentence() const;
	bool isEmpty() const;

private:
	QString _word;
	QString _punctuationText;
	Delimiter _delimitier = NoDelimiter;
};
