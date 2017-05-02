#CREATE DATABASE teamtalk;
use teamtalk;

#DROP TABLE IMUser;
CREATE TABLE IF NOT EXISTS IMUser (
	id int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '用户id',
	sex tinyint(1) unsigned NOT NULL DEFAULT '0' COMMENT '1男 2女 0 未知',
	name varchar(32) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '用户名',
	domain varchar(32) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '拼音',
	nick varchar(32) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '花名',
	password varchar(32) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '密码',
	salt varchar(4) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '混淆码',
	phone varchar(11) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '手机号码',
	email varchar(64) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '手机号码',
	avatar varchar(255) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '手机号码',
	sign_info varchar(255) COLLATE utf8mb4_bin NOT NULL DEFAULT '' COMMENT '个性签名',
	departId int(11) unsigned NOT NULL COMMENT '所属部门Id',
	status tinyint(2) unsigned NOT NULL DEFAULT '0' COMMENT '1. 试用期 2. 正式 3. 离职 4. 实习',
	created int(11) unsigned NOT NULL COMMENT '创建时间',
	updated int(11) unsigned NOT NULL COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_name (name),
	KEY idx_domain (domain),
	KEY idx_phone (phone)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

CREATE TABLE  IF NOT EXISTS IMRecentSession (
	id int(11) NOT NULL AUTO_INCREMENT,
	userId int(11) unsigned NOT NULL COMMENT '用户id',
	peerId int(11) unsigned NOT NULL COMMENT '对方id',
	type tinyint(3) unsigned DEFAULT '0' COMMENT '类型，1-用户，2-群组',
	status tinyint(1) unsigned DEFAULT '0' COMMENT '用户:0-正常，1-用户A删除，群组0-正常，1-被删除',
	created int(11) unsigned NOT NULL DEFAULT '0' COMMENT '创建时间',
	updated int(11) unsigned NOT NULL DEFAULT '0' COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_userId_peerId_status_updated (userId,peerId,status,updated),
	KEY idx_userId_peerId_type (userId,peerId,type) 
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


CREATE TABLE  IF NOT EXISTS IMRelationShip (
	id int(11) NOT NULL AUTO_INCREMENT,
	smallId int(11) unsigned NOT NULL COMMENT '用户A id',
	bigId int(11) unsigned NOT NULL COMMENT '用户B id',
	status tinyint(1) unsigned DEFAULT '0' COMMENT '用户:0-正常，1-用户A删除，群组0-正常，1-被删除',
	created int(11) unsigned NOT NULL DEFAULT '0' COMMENT '创建时间',
	updated int(11) unsigned NOT NULL DEFAULT '0' COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_smallId_bigId_status_updated (smallId,bigId,status,updated)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS  IMGroup (
	id int(11) NOT NULL AUTO_INCREMENT,
	name varchar(256)  NOT NULL DEFAULT ''  COMMENT '群名称',
	avatar varchar(256)  NOT NULL DEFAULT ''  COMMENT '群头像',
	creator int(11) unsigned NOT NULL DEFAULT '0'  COMMENT '创建者用户 id',
	type tinyint(3) unsigned NOT NULL DEFAULT '1'  COMMENT '群组类型，1-固定，2-临时群',
	userCnt int(11) unsigned NOT NULL DEFAULT 0 COMMENT '成员人数',
	status tinyint(3) unsigned DEFAULT 0 COMMENT '是否删除:0-正常，1-删除',
	version int(11) unsigned NOT NULL DEFAULT 1 COMMENT '群版本号',
	lastChated int(11) unsigned NOT NULL DEFAULT 0 COMMENT '最后聊天时间',
	created int(11) unsigned NOT NULL DEFAULT '0' COMMENT '创建时间',
	updated int(11) unsigned NOT NULL DEFAULT '0' COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_name (name(191)),
	KEY idx_creator (creator)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS  IMGroupMember (
	id int(11) NOT NULL AUTO_INCREMENT,
	groupId int(11)  NOT NULL   COMMENT '群id',
	userId int(11)  NOT NULL  COMMENT '用户id',
	status tinyint(4) unsigned NOT NULL DEFAULT 0 COMMENT '是否退出群，0-正常，1-已退出',
	creator int(11) unsigned NOT NULL DEFAULT '0'  COMMENT '创建者用户 id',
	type tinyint(3) unsigned NOT NULL DEFAULT '1'  COMMENT '群组类型，1-固定，2-临时群',
	created int(11) unsigned NOT NULL DEFAULT '0' COMMENT '创建时间',
	updated int(11) unsigned NOT NULL DEFAULT '0' COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_groupId_userId_status (groupId,userId,status),
	KEY idx_creator (creator)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS  IMMessage_0 (
	id int(11) NOT NULL AUTO_INCREMENT,
	relateId int(11) unsigned  NOT NULL  COMMENT '用户的关系id',
	fromId int(11) unsigned  NOT NULL  COMMENT '发送用户的id',
	toId int(11) unsigned  NOT NULL  COMMENT '接收用户的id',
	msgId int(11) unsigned  NOT NULL  COMMENT '消息的id',
	content varchar(4096) DEFAULT '' COMMENT '消息内容',
	type tinyint(3) unsigned NOT NULL DEFAULT '1'  COMMENT '消息内容',
	status tinyint(4) unsigned NOT NULL DEFAULT 0 COMMENT '0-正常，1-被删除',
	created int(11) unsigned NOT NULL DEFAULT '0' COMMENT '创建时间',
	updated int(11) unsigned NOT NULL DEFAULT '0' COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_relateId_status_created (relateId,status,created),
	KEY idx_relateId_status_msgId_created (relateId,status,msgId,created),
	KEY idx_fromId_toId_created (fromId,toId,status)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


