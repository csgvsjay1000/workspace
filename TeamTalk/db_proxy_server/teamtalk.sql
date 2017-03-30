#CREATE DATABASE teamtalk;
use teamtalk;

#DROP TABLE IMUser;
CREATE TABLE IMUser(
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
	departId int(11) unsigned NOT NULL COMMENT '所属部门Id',
	status tinyint(2) unsigned NOT NULL DEFAULT '0' COMMENT '1. 试用期 2. 正式 3. 离职 4. 实习',
	created int(11) unsigned NOT NULL COMMENT '创建时间',
	updated int(11) unsigned NOT NULL COMMENT '更新时间',
	PRIMARY KEY (id),
	KEY idx_name (name),
	KEY idx_domain (domain),
	KEY idx_phone (phone)
)ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

