/*
 * frontend.cpp - frontend widget for invoking ffmpeg2theora
 * This file is part of QTheoraFrontend.
 *
 * Copyright (C) 2009  Denver Gingerich <denver@ossguy.com>
 *
 * The contents of this file can be redistributed and/or modified under the
 * terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see http://www.gnu.org/licenses/.
 *
 */

#include "frontend.h"
#include <QVBoxLayout>
#include <QProcess>
#include <QDebug>

#define BUF_SIZE 256

Frontend::Frontend(QWidget* parent)
	: QWidget(parent)
{
	instructions = new QLabel;
	convert = new QPushButton(tr("&Convert"));
	status = new QLabel;

	instructions->setText(tr("Instructions will go here."));
        instructions->setWordWrap(true);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(instructions);
	layout->addWidget(convert);
	layout->addWidget(status);
	setLayout(layout);

	// when user clicks "Convert", start transcoding
	connect(convert, SIGNAL(released()), this, SLOT(transcode()));
}

void Frontend::transcode()
{
	char buf[BUF_SIZE];
	QProcess* proc = new QProcess;

	proc->setReadChannel(QProcess::StandardError);
	proc->start("ffmpeg2theora", QStringList() << "--frontend"
		<< "test.flv");

	proc->waitForStarted();
	proc->waitForReadyRead();

	while (proc->readLine(buf, BUF_SIZE) > 0) {
		status->setText(QString(buf));
		qDebug() << buf;
		proc->waitForReadyRead();
	}
}
